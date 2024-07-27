/*
 * @lc app=leetcode id=2976 lang=cpp
 *
 * [2976] Minimum Cost to Convert String I
 */

// @lc code=start
#define THRESHOLD 1e7
class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original,
                          vector<char> &changed, vector<int> &cost)
    {
        int n = original.size();
        int costs[26][26];

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
                costs[i][j] = THRESHOLD;
            costs[i][i] = 0;
        }

        int x, y;
        for (int i = 0; i < n; i++)
        {
            x = original[i] - 'a';
            y = changed[i] - 'a';
            costs[x][y] = min(cost[i], costs[x][y]);
        }

        for (int k = 0; k < 26; ++k)
        {
            for (int i = 0; i < 26; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        long long sum = 0;
        int nn = source.size();
        for (int i = 0; i < nn; i++)
        {
            if (source[i] == target[i])
                continue;
            x = source[i] - 'a';
            y = target[i] - 'a';
            if (costs[x][y] >= THRESHOLD)
                return -1;
            else
                sum += costs[x][y];
        }
        return sum;
    }
};
// @lc code=end

// Note: graph