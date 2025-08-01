/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> last_v;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> v(i + 1);
            v[0] = 1;
            if (i > 0)
                v[i] = 1;

            for (int j = 1; j < i; j++)
                v[j] = last_v[j - 1] + last_v[j];

            ans.push_back(v);
            last_v = v;
        }
        return ans;
    }
};
// @lc code=end
