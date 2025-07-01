/*
 * @lc app=leetcode id=3330 lang=cpp
 *
 * [3330] Find the Original Typed String I
 */

// @lc code=start
class Solution
{
public:
    int possibleStringCount(string word)
    {
        int n = word.size();
        int cnt = 1;
        for (int i = 1; i < n; ++i)
        {
            if (word[i - 1] == word[i])
                ++cnt;
        }
        return cnt;
    }
};
// @lc code=end
