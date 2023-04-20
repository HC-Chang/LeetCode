/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        queue<vector<int>> q;
        q.push({nums[0]});
        int n, m;
        for (int i = 1; i < nums.size(); i++)
        {
            n = q.size();
            for (int j = 0; j < n; j++)
            {
                auto p = q.front();
                q.pop();

                m = p.size();
                for (int k = 0; k <= m; k++)
                {
                    auto temp = p;
                    temp.insert(temp.begin() + k, nums[i]);
                    q.push(temp);
                }
            }
        }

        vector<vector<int>> results;
        while (!q.empty())
        {
            results.push_back(q.front());
            q.pop();
        }
        return results;
    }
};
// @lc code=end
