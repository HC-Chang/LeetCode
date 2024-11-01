/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans;
        char cc = ' ';
        int cnt = 1;
        for (auto c : s)
        {
            if (c != cc)
            {
                cc = c;
                cnt = 1;
            }
            else if (++cnt >= 3)
                continue;
            ans += c;
        }
        return ans;
    }
};
// @lc code=end

// Note: string