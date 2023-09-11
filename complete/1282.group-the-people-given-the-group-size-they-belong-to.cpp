/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
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
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int n = groupSizes.size();
        vector<vector<int>> res, all(n + 1);
        for (int i = 0; i < n; ++i)
        {
            all[groupSizes[i]].push_back(i);
            if (all[groupSizes[i]].size() == groupSizes[i])
            {
                res.push_back(all[groupSizes[i]]);
                all[groupSizes[i]].clear();
            }
        }
        return res;
    }
};
// @lc code=end

// Note: hash table