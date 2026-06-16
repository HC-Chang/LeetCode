/*
 * @lc app=leetcode id=3612 lang=cpp
 *
 * [3612] Process String with Special Operations I
 */

// @lc code=start
class Solution
{
public:
    string processStr(string s)
    {
        string ans;
        for (auto &c : s)
        {
            if (islower(c))
                ans += c;
            else if (c == '#')
                ans += ans;
            else if (c == '%')
                reverse(ans.begin(), ans.end());
            else if (c == '*' && ans.size() > 0)
                ans.pop_back();
        }
        return ans;
    }
};
// @lc code=end
