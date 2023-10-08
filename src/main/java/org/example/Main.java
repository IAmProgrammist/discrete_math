package org.example;

import com.codeborne.selenide.Configuration;
import com.codeborne.selenide.Selenide;
import org.openqa.selenium.*;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;
import org.openqa.selenium.interactions.Actions;
import org.w3c.dom.html.HTMLElement;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;


public class Main {
    public static void main(String[] args) throws InterruptedException {
        File folder = new File("output");
        File save = new File("images");
        File[] folderEntries = folder.listFiles();
        for (File entry : folderEntries)
        {
            try (BufferedReader r = new BufferedReader(new FileReader(entry, StandardCharsets.UTF_8))) {
                String data = "";
                while (r.ready()) {
                    data += r.readLine() + "\n";
                }
                ChromeOptions options = new ChromeOptions();
                Map<String, Object> prefs = new HashMap<>();
                //This will set the path of the download folder
                prefs.put("download.default_directory", save.getAbsolutePath());

                options.setExperimentalOption("prefs", prefs);

                ChromeDriver driver = new ChromeDriver(options);
                driver.get("https://programforyou.ru/graph-redactor");
                // Избавляемся от перемешивания графа
                JavascriptExecutor js = (JavascriptExecutor) driver;
                js.executeScript("GraphRedactor.prototype.PlaceByCircle =function(){let bbox=this.GetViewAreaBoundingBoxReal()\n" +
                        "let maxRadius=this.GetMaxVertexRadius()\n" +
                        "let x0=(bbox.xmin+bbox.xmax)/2\n" +
                        "let y0=(bbox.ymin+bbox.ymax)/2\n" +
                        "let radius=Math.min(bbox.xmax-bbox.xmin,bbox.ymax-bbox.ymin)/2-maxRadius-GRID_SIZE\n" +
                        "let vertices=this.vertices.ToArray()\n" +
                        "let prevCoordinates=this.GetVerticesCoordinates(vertices)\n" +
                        "let angle=2*Math.PI/vertices.length\n" +
                        "let indices=vertices.map((v,i)=>i)\n" +
                        "for(let i=0;i<vertices.length;i++){vertices[indices[i]].x=x0+radius*Math.cos(angle*i)\n" +
                        "vertices[indices[i]].y=y0+radius*Math.sin(angle*i)}this.AddVerticesMovementToUndo(vertices,prevCoordinates)}");
                driver.manage().window().setSize(new Dimension(1024,768));

                WebElement root = driver.findElement(By.cssSelector("canvas"));
                Dimension size = root.getSize();
                new Actions(driver).moveToElement(root).moveByOffset(-size.getWidth() / 2 + 992,-size.getHeight() / 2 + 165 - 58).clickAndHold().build().perform();
                new Actions(driver).moveToElement(root).moveByOffset(-size.getWidth() / 2 + 85,-size.getHeight() / 2 + 302 - 58).click().build().perform();
                Thread.sleep(100);
                new Actions(driver).moveToElement(root).moveByOffset(-size.getWidth() / 2 + 390,-size.getHeight() / 2 + 387 - 58).click().build().perform();
                new Actions(driver).moveToElement(root).sendKeys(data).build().perform();
                new Actions(driver).moveToElement(root).moveByOffset(-size.getWidth() / 2 + 734,-size.getHeight() / 2 + 553 - 58).click().build().perform();
                driver.switchTo().alert().accept();
                new Actions(driver).moveToElement(root).moveByOffset(-size.getWidth() / 2 + 144,-size.getHeight() / 2 + 438 - 58).click().build().perform();
                Thread.sleep(100);
                new Actions(driver).moveToElement(root).moveByOffset(-size.getWidth() / 2 + 355,-size.getHeight() / 2 + 513 - 58).click().build().perform();
                new Actions(driver).moveToElement(root).moveByOffset(-size.getWidth() / 2 + 176,-size.getHeight() / 2 + 346 - 58).click().build().perform();
                Thread.sleep(100);
                new Actions(driver).moveToElement(root).moveByOffset(-size.getWidth() / 2 + 308,-size.getHeight() / 2 + 398 - 58).click().build().perform();

                Thread.sleep(500);
                driver.close();

                File f = new File(save.getAbsoluteFile() + "/graph.png");
                String newName = entry.getName().substring(0, entry.getName().length() - 4) + ".png";
                if (newName.contains("Mi")) {
                    newName = newName.split("Mi")[0] + "Mi" + "P" + newName.split("P")[1];
                } else {
                    newName = newName.split("Ma")[0] + "Ma" + "P" + newName.split("P")[1];
                }
                f.renameTo(new File(f.getParentFile().getAbsoluteFile() + "/" + newName));

            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}