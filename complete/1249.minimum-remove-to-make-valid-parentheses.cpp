/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string ans;
        int l = 0;
        int r = 0;
        for (auto c : s)
        {
            if (c == ')')
                ++r;
        }
        for (auto c : s)
        {
            if (c == '(')
            {
                if (l == r)
                    continue;
                ++l;
            }
            else if (c == ')')
            {
                --r;
                if (l == 0)
                    continue;
                --l;
            }
            ans += c;
        }
        return ans;
    }
};
// @lc code=end

// Note: stack