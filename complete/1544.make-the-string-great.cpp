/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution
{
public:
    string makeGood(string s)
    {
        int n = s.size();
        int idx = 1;
        for (int i = 1; i < n; i++)
        {
            if (idx > 0 && abs(s[i] - s[idx - 1]) == 32)
                idx--;
            else
                s[idx++] = s[i];
        }
        s = s.substr(0, idx);
        return s;
    }
};
// @lc code=end

// Note: stack