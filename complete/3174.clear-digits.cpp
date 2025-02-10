/*
 * @lc app=leetcode id=3174 lang=cpp
 *
 * [3174] Clear Digits
 */

// @lc code=start
class Solution
{
public:
    string clearDigits(string s)
    {
        string ans;
        for (auto c : s)
        {
            if (isdigit(c))
                ans.pop_back();
            else
                ans += c;
        }
        return ans;
    }
};
// @lc code=end

// Note: stack