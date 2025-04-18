/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution
{
public:
    string help(string s)
    {
        string ans;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while (i + 1 < n && s[i] == s[i + 1])
            {
                cnt++;
                i++;
            }
            ans += to_string(cnt) + s[i];
        }
        return ans;
    }

    string countAndSay(int n)
    {
        string s = "1";
        for (int i = 0; i < n - 1; i++)
            s = help(s);

        return s;
    }
};
// @lc code=end
