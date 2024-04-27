/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */

// @lc code=start
class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        int m = key.size();
        int n = ring.size();
        vector<int> pos[26];
        for (int j = 0; j < n; ++j)
            pos[ring[j] - 'a'].push_back(j);

        int f[m][n];
        memset(f, 0x3f, sizeof(f));
        for (int j : pos[key[0] - 'a'])
            f[0][j] = min(j, n - j) + 1;

        for (int i = 1; i < m; ++i)
        {
            for (int j : pos[key[i] - 'a'])
            {
                for (int k : pos[key[i - 1] - 'a'])
                    f[i][j] = min(f[i][j], f[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
            }
        }
        int ans = INT_MAX;
        for (int j : pos[key[m - 1] - 'a'])
            ans = min(ans, f[m - 1][j]);

        return ans;
    }
};
// @lc code=end

// Note: DP + DFS/BFS