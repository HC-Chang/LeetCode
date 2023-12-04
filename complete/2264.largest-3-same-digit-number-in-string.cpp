/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 */

// @lc code=start
class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string ans = "";
        int val = -1;
        int n = num.size();
        int count = 1;
        char c = num[0];
        int tmp;
        for (int i = 1; i < n; i++)
        {
            if (num[i] == c)
            {
                if (++count == 3)
                {
                    tmp = num[i] - '0';
                    if (val == -1 || tmp > val)
                        val = tmp;
                }
            }
            else
            {
                c = num[i];
                count = 1;
            }
        }
        if (val != -1)
        {
            for (int i = 0; i < 3; i++)
                ans += val + '0';
        }

        return ans;
    }
};
// @lc code=end
