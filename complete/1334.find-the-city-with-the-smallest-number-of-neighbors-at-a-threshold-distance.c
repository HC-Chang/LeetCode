/*
 * @lc app=leetcode id=1334 lang=c
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
int findTheCity(int n, int **edges, int edgesSize, int *edgesColSize,
                int distanceThreshold)
{
    int dist[n][n];
    int res = 0;
    int min_reachable = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
            dist[i][j] = 1e6;
    }

    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (int i = 0; i < edgesSize; i++)
    {
        dist[edges[i][0]][edges[i][1]] = edges[i][2];
        dist[edges[i][1]][edges[i][0]] = edges[i][2];
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dist[i][j] = fmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int reachable = 0;
        for (int j = 0; j < n; ++j)
        {
            if (dist[i][j] <= distanceThreshold)
                ++reachable;
        }

        if (reachable <= min_reachable)
        {
            min_reachable = reachable;
            res = i;
        }
    }
    return res;
}
// @lc code=end

// Note: DP