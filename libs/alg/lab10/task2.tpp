template <typename T>
DominantRelation<T> Relation<T>::getDominantRelation()
{
    if (!isOrdered())
        throw std::invalid_argument("Original relation should be relation of order");

    DominantRelation<T> result(origin, [](T, T)
                               { return false; });
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (!data[x][y])
                continue;
            bool anyZ = false;

            for (int z = 0; z < size && !anyZ; z++)
            {
                if (data[x][z] && data[z][y])
                    anyZ = true;
            }

            result.data[x][y] = !anyZ;
        }
    }

    return result;
}