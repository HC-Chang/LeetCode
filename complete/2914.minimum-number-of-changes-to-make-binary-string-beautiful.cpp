/*
 * @lc app=leetcode id=2914 lang=cpp
 *
 * [2914] Minimum Number of Changes to Make Binary String Beautiful
 */

// @lc code=start
class Solution
{
public:
    int minChanges(string s)
    {
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i * 2] != s[i * 2 + 1])
                cnt++;
        }

        return cnt;
    }
};
// @lc code=end
