/*
 * @lc app=leetcode id=959 lang=c
 *
 * [959] Regions Cut By Slashes
 */

// @lc code=start
    int find(int *parentArray, int node)
    {
        if (parentArray[node] == -1)
            return node;

        return parentArray[node] = find(parentArray, parentArray[node]);
    }

    int union_sets(int *parentArray, int node1, int node2)
    {
        int parent1 = find(parentArray, node1);
        int parent2 = find(parentArray, node2);

        if (parent1 == parent2)
            return 1;

        parentArray[parent2] = parent1;
        return 0;
    }
    int regionsBySlashes(char **grid, int gridSize)
    {
        int pointsPerSide = gridSize + 1;
        int totalPoints = pointsPerSide * pointsPerSide;

        int *parentArray = malloc(totalPoints * sizeof(int));
        for (int i = 0; i < totalPoints; i++)
            parentArray[i] = -1;

        for (int i = 0; i < pointsPerSide; i++)
        {
            for (int j = 0; j < pointsPerSide; j++)
            {
                if (i == 0 || j == 0 || i == pointsPerSide - 1 ||
                    j == pointsPerSide - 1)
                {
                    int point = i * pointsPerSide + j;
                    parentArray[point] = 0;
                }
            }
        }

        parentArray[0] = -1;
        int regionCount = 1;

        for (int i = 0; i < gridSize; i++)
        {
            for (int j = 0; j < gridSize; j++)
            {
                if (grid[i][j] == '/')
                {
                    int topRight = i * pointsPerSide + (j + 1);
                    int bottomLeft = (i + 1) * pointsPerSide + j;
                    regionCount +=
                        union_sets(parentArray, topRight, bottomLeft);
                }
                else if (grid[i][j] == '\\')
                {
                    int topLeft = i * pointsPerSide + j;
                    int bottomRight = (i + 1) * pointsPerSide + (j + 1);
                    regionCount +=
                        union_sets(parentArray, topLeft, bottomRight);
                }
            }
        }

        return regionCount;
    }
// @lc code=end

// Note: union find

// Official Solution