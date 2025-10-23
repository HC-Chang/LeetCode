/*
 * @lc app=leetcode id=3461 lang=cpp
 *
 * [3461] Check If Digits Are Equal in String After Operations I
 */

// @lc code=start
class Solution
{
public:
    bool hasSameDigits(string s)
    {
        while (s.size() > 2)
        {
            string tmp;
            int n = s.size();
            int ii;
            for (int i = 0; i < n - 1; i++)
                tmp += ((s[i] - '0' + s[i + 1] - '0') % 10) + '0';
            s = tmp;
        }
        if (s.size() == 2 && s[0] == s[1])
            return true;
        return false;
    }
};
// @lc code=end

// Note: simulation
