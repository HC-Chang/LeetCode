/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int cnt = 0;
        int tmp = 0;
        while (cnt < a.size() || cnt < b.size())
        {
            int val = 0;
            if (cnt < a.size() && cnt < b.size())
                val += a[cnt] - '0' + b[cnt] - '0' + tmp;
            else if (cnt < a.size())
                val += a[cnt] - '0' + tmp;
            else if (cnt < b.size())
                val += b[cnt] - '0' + tmp;
            ans += val % 2 + '0';
            tmp = val / 2;
            cnt++;
        }
        if (tmp == 1)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
