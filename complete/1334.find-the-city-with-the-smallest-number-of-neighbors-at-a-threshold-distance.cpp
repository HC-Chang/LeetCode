/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
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

        for (auto &edge : edges)
        {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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
};
// @lc code=end

// Note: DP