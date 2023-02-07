#!/bin/bash
RED="\e[31m"
GREEN="\e[32m"
WHITE="\e[97m"
ENDCOLOR="\e[0m"

FAILED_TESTS=0
FULL_TOTAL_TESTS=0

# TODO: Надо сделать gui, ибо редактировать json файл напрямую могут только психи
# TODO: lablist.json - классное название. Для моего репозитория, надо вынести путь в параметры
# TODO: добавить аргументы для запуска исполняемого файла в mock тестах
process_labs() {

  CURRENT_LAB_INDEX=0
  TOTAL_LABS=$(jq '.labs | length' ./lablist.json)
  BUILD_DIR=$(jq -r ".build_dir" ./lablist.json)
  mkdir -p ${BUILD_DIR}

  echo -e "Сборка CMake..."
  # TODO: В текущем варианте требуется добавлять некоторые значения в CMakeLists.txt, надо починить.
  cmake -DCMAKE_BUILD_TYPE=Debug ninja -G Ninja -S. -B ${BUILD_DIR}

  echo -e "${TOTAL_LABS} ${BUILD_DIR}"
  while [ $CURRENT_LAB_INDEX != $TOTAL_LABS ]; do
    ENABLED_LAB=$(jq -r ".labs[${CURRENT_LAB_INDEX}].enabled" ./lablist.json)
    LAB_ID=$(jq -r ".labs[${CURRENT_LAB_INDEX}].labid" ./lablist.json)
    LAB_NAME=$(jq -r ".labs[${CURRENT_LAB_INDEX}].labname" ./lablist.json)
    if [ $ENABLED_LAB == "true" ] || [ $ENABLED_LAB = "null" ]; then
      echo -e "Запуск тестов к заданиям по лабораторной работе по ОП и ОА №${WHITE}${LAB_ID}${ENDCOLOR}"
      echo -e "Название: '${WHITE}${LAB_NAME}${ENDCOLOR}'"
      RELATIVE_PATH=$(jq -r ".labs[${CURRENT_LAB_INDEX}].testsfilepath" ./lablist.json)
      TESTS_FILE_NAME=$(jq -r ".labs[${CURRENT_LAB_INDEX}].testsfilename" ./lablist.json)
      RELATIVE_PATH_FILE_TESTS=${RELATIVE_PATH}/${TESTS_FILE_NAME}
      process_lab
    else
      echo -e "Пропуск лабораторной работы ${WHITE}${LAB_ID}${ENDCOLOR}"
    fi
    CURRENT_LAB_INDEX=$((CURRENT_LAB_INDEX+1))
  done
}

process_lab() {
  CURRENT_TASK_INDEX=0
  TOTAL_TASKS=$(jq '.tasks | length' ${RELATIVE_PATH_FILE_TESTS})
  echo "Всего задач: ${TOTAL_TASKS}"
  while [ $CURRENT_TASK_INDEX != $TOTAL_TASKS ]; do
      ENABLED_TASK=$(jq -r ".tasks[${CURRENT_TASK_INDEX}].enabled" ${RELATIVE_PATH_FILE_TESTS})
      TASK_NUMBER=$(jq ".tasks[${CURRENT_TASK_INDEX}].tasknum" ${RELATIVE_PATH_FILE_TESTS})
      if [ $ENABLED_TASK == "true" ] || [ $ENABLED_TASK == "null" ]; then
        echo -e "Задача №${WHITE}${TASK_NUMBER}${ENDCOLOR}"
        echo -e "${WHITE}Компиляция...${ENDCOLOR}"
        TARGET=$(jq -r ".tasks[${CURRENT_TASK_INDEX}].cmakelistname" ${RELATIVE_PATH_FILE_TESTS})
        cmake --build ${BUILD_DIR} --target ${TARGET} -j 12

        process_tests
        rm ${BUILD_DIR}/bin/$(jq -r ".tasks[${CURRENT_TASK_INDEX}].cmakelistname" ${RELATIVE_PATH_FILE_TESTS})
      else
        echo -e "Пропуск задачи №${WHITE}${TASK_NUMBER}${ENDCOLOR}"
      fi
      CURRENT_TASK_INDEX=$((CURRENT_TASK_INDEX+1))
  done

}

process_tests() {
  TEST_TYPE=$(jq -r ".tasks[${CURRENT_TASK_INDEX}].testtype" ${RELATIVE_PATH_FILE_TESTS})
  if [ $TEST_TYPE == "mock" ]; then
    CURRENT_TEST_INDEX=0
    TOTAL_TESTS=$(jq -r ".tasks[${CURRENT_TASK_INDEX}].tests | length" ${RELATIVE_PATH_FILE_TESTS})
    echo "Всего тестов: ${TOTAL_TESTS}"
    FULL_TOTAL_TESTS=$((FULL_TOTAL_TESTS+TOTAL_TESTS))
    while [ $CURRENT_TEST_INDEX != $TOTAL_TESTS ]; do
      TEST_NUMBER=$((CURRENT_TEST_INDEX+1))
      ENABLED_TEST=$(jq -r ".tasks[${CURRENT_TASK_INDEX}].tests[${CURRENT_TEST_INDEX}].enabled" ${RELATIVE_PATH_FILE_TESTS})

      if [ $ENABLED_TEST == "true" ] || [ $ENABLED_TEST == "null" ]; then
        if [ $(jq ".tasks[${CURRENT_TASK_INDEX}].tests[${CURRENT_TEST_INDEX}].input" ${RELATIVE_PATH_FILE_TESTS} | jq -r 'type') == "array" ]; then
          INPUT=$(jq -r ".tasks[${CURRENT_TASK_INDEX}].tests[${CURRENT_TEST_INDEX}].input | map(.) | join(\"\n\")" ${RELATIVE_PATH_FILE_TESTS})
        else
          INPUT=$(jq -r ".tasks[${CURRENT_TASK_INDEX}].tests[${CURRENT_TEST_INDEX}].input" ${RELATIVE_PATH_FILE_TESTS})
        fi
        EXPOUTPUT=$(jq -r ".tasks[${CURRENT_TASK_INDEX}].tests[${CURRENT_TEST_INDEX}].output" ${RELATIVE_PATH_FILE_TESTS})
        EXPLANATION=$(jq -r ".tasks[${CURRENT_TASK_INDEX}].tests[${CURRENT_TEST_INDEX}].explanation" ${RELATIVE_PATH_FILE_TESTS})
        process_test_mock
      else
         echo -e "Пропуск теста №${WHITE}${TEST_NUMBER}${ENDCOLOR}"
      fi

      CURRENT_TEST_INDEX=$((CURRENT_TEST_INDEX+1))
    done
  elif [ $TEST_TYPE == "unit" ]; then
    TEST_NUMBER=$(jq -r ".tasks[${CURRENT_TASK_INDEX}].tasknum" ${RELATIVE_PATH_FILE_TESTS})
    process_test_unit
    FULL_TOTAL_TESTS=$((FULL_TOTAL_TESTS+1))
  else
    echo -e "${RED}Тип теста не распознан: ${TEST_TYPE}${ENDCOLOR}"
    FAILED_TESTS=$((FAILED_TESTS+1))
  fi
}

process_test_unit() {
  echo "Тест №${TEST_NUMBER}"
  echo -e "${WHITE}Запуск Unit-теста...${ENDCOLOR}"
  ${BUILD_DIR}/bin/$(jq -r ".tasks[${CURRENT_TASK_INDEX}].cmakelistname" ${RELATIVE_PATH_FILE_TESTS})
  OUTPUT=$?
  if [ $OUTPUT -eq 0 ]; then
    echo -e "${GREEN}ОК${ENDCOLOR}"
  else
    echo -e "${RED}ОШИБКА${ENDCOLOR}"
    FAILED_TESTS=$((FAILED_TESTS+1))
  fi
}
process_test_mock() {
  echo "Тест №${TEST_NUMBER}"
  echo "Ввод:"
  echo -e "${WHITE}${INPUT}${ENDCOLOR}"
  echo -e "Ожидаемый вывод:"
  echo -e "${WHITE}${EXPOUTPUT}${ENDCOLOR}"
  echo -e "Пояснение:"
  echo -e "${WHITE}${EXPLANATION}${ENDCOLOR}"
  echo -e "${WHITE}Запуск теста...${ENDCOLOR}"
  OUTPUT=`${BUILD_DIR}/bin/$(jq -r ".tasks[${CURRENT_TASK_INDEX}].cmakelistname" ${RELATIVE_PATH_FILE_TESTS}) <<EOD
${INPUT}
EOD`
  if [ "$OUTPUT" == "$EXPOUTPUT" ]; then
    echo -e "${GREEN}ОК${ENDCOLOR}"
  else
    echo -e "${RED}ОШИБКА${ENDCOLOR}"

    echo -e "Ожидаемый вывод:"
    echo -e "${WHITE}${EXPOUTPUT}${ENDCOLOR}"

    echo -e "Действительный вывод:"
    echo -e "${WHITE}${OUTPUT}${ENDCOLOR}"
    FAILED_TESTS=$((FAILED_TESTS+1))
  fi
}


process_labs

if [ $FAILED_TESTS -gt 0 ]; then
    echo -e "${RED}Выполнено тестов: ${FULL_TOTAL_TESTS}, из них выполнено с ошибкой: ${FAILED_TESTS} ${ENDCOLOR}"
    exit 1
else
    echo -e "${GREEN}Выполнено тестов: ${FULL_TOTAL_TESTS}, из них выполнено с ошибкой: ${FAILED_TESTS} ${ENDCOLOR}"
    exit 0
fi



