/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int flag = 0;
            int tmp_cnt = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (flag == 1)
                        break;
                    tmp_cnt++;
                }
                else
                {
                    flag = 1;
                    if (--tmp_cnt == 0)
                    {
                        cnt++;
                        break;
                    }
                }
            }
        }

        return cnt;
    }
};
// @lc code=end

// Note: two pointers