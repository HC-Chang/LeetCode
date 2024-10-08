/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

// @lc code=start
class Solution
{
public:
    int minSwaps(string s)
    {
        int stackSize = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '[')
                stackSize++;
            else
            {
                if (stackSize > 0)
                    stackSize--;
            }
        }
        return (stackSize + 1) / 2;
    }
};
// @lc code=end

// Note: stack

// Official Solution