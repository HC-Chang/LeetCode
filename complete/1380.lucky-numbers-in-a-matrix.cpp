/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int, int> hash;

        int tmp;
        for (int i = 0; i < m; i++)
        {
            tmp = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < tmp)
                    tmp = matrix[i][j];
            }
            hash[tmp] = 1;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            tmp = INT_MIN;
            for (int j = 0; j < m; j++)
            {
                if (matrix[j][i] > tmp)
                    tmp = matrix[j][i];
            }
            if (hash[tmp])
                ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end

// Note: matrix + hash table