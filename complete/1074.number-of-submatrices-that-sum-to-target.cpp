/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
                matrix[i][j] += matrix[i][j - 1];
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                unordered_map<int, int> hash{{0, 1}};
                int cur = 0;
                for (int k = 0; k < m; ++k)
                {
                    cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    res += hash[cur - target];
                    ++hash[cur];
                }
            }
        }
        return res;
    }
};
// @lc code=end

// Note: prefix sum + sliding window