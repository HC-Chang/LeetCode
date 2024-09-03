/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
class Solution
{
public:
    int getLucky(string s, int k)
    {
        int n = s.size();
        string ss = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                ss += to_string(s[i] - 'a' + 1);
            else if (s[i] >= '0' && s[i] <= '9')
                ss += s[i];
        }

        int ans = 0;
        int tmp = 0;
        for (int i = 0; i < ss.size(); i++)
            tmp += ss[i] - '0';

        ans = tmp;
        for (int i = 0; i < k - 1; i++)
        {
            tmp = 0;
            while (ans)
            {
                tmp += ans % 10;
                ans /= 10;
            }
            ans = tmp;
        }

        return ans;
    }
};
// @lc code=end
