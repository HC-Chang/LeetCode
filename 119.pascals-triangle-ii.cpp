/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> r(rowIndex + 1);
        r[0] = 1;
        for (int i = 1; i <= rowIndex; ++i)
        {
            for (int j = i; j >= 1; --j)
                r[j] += r[j - 1];
        }
        return r;
    }
};
// @lc code=end
