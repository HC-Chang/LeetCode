/*
 * @lc app=leetcode id=815 lang=c
 *
 * [815] Bus Routes
 */

// @lc code=start
int numBusesToDestination(int **routes, int routesSize, int *routesColSize, int source, int target)
{
    if (source == target)
        return 0;
    bool visited_routes[routesSize];
    int hash[100001];
    memset(visited_routes, false, sizeof(visited_routes));
    memset(hash, -1, sizeof(hash));
    int size = routesSize;
    for (int i = 0; i < routesSize; i++)
    {
        for (int j = 0; j < routesColSize[i]; j++)
        {
            if (routes[i][j] == source)
            {
                visited_routes[i] = true;
                size--;
                for (j = 0; j < routesColSize[i]; j++)
                    hash[routes[i][j]] = 1;
                break;
            }
        }
    }
    if (size == routesSize)
        return -1;
    if (hash[target] != -1)
        return hash[target];
    bool flag;
    while (size > 0)
    {
        flag = false;
        for (int i = 0; i < routesSize; i++)
        {
            if (visited_routes[i] == true)
                continue;
            int min = INT_MAX;
            for (int j = 0; j < routesColSize[i]; j++)
            {
                if (hash[routes[i][j]] != -1)
                    min = fmin(min, hash[routes[i][j]]);
            }
            if (min != INT_MAX)
            {
                flag = true;
                visited_routes[i] = true;
                size--;
                for (int j = 0; j < routesColSize[i]; j++)
                {
                    if (hash[routes[i][j]] == -1)
                        hash[routes[i][j]] = min + 1;
                }
            }
            if (hash[target] != -1 || size <= 0)
                break;
        }
        if (hash[target] != -1 || size <= 0 || !flag)
            break;
    }
    return hash[target];
}
// @lc code=end

// Official Solution