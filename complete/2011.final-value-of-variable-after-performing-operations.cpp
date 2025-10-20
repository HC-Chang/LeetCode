/*
 * @lc app=leetcode id=2011 lang=cpp
 *
 * [2011] Final Value of Variable After Performing Operations
 */

// @lc code=start
class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int val = 0;
        for (auto &s : operations)
        {
            if (s == "++X" || s == "X++")
                val++;
            else if (s == "--X" || s == "X--")
                val--;
        }
        return val;
    }
};
// @lc code=end
