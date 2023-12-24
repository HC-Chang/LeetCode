/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

// @lc code=start
class Solution
{
public:
    int minOperations(string s)
    {
        int alt = 0;
        int n = s.size();
        int chk;
        for (int i = 0; i < n; i++)
        {
            chk = i % 2;
            if (s[i] - '0' == chk)
                ++alt;
        }

        return min(alt, n - alt);
    }
};
// @lc code=end
