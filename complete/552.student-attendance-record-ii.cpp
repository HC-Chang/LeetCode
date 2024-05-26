/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 */

// @lc code=start
class Solution
{
public:
    int checkRecord(int n)
    {
        int M = 1e9 + 7;
        vector<long> P(n + 1), PorL(n + 1);
        PorL[0] = 1;
        PorL[1] = 2;
        P[0] = 1;
        P[1] = PorL[0];
        for (int i = 2; i <= n; ++i)
        {
            P[i] = PorL[i - 1];
            PorL[i] = (P[i] + P[i - 1] + P[i - 2]) % M;
        }

        int res = PorL[n];
        for (int i = 0; i < n; ++i)
        {
            int t = (PorL[i] * PorL[n - 1 - i]) % M;
            res = (res + t) % M;
        }
        return res;
    }
};
// @lc code=end

// Note: DP