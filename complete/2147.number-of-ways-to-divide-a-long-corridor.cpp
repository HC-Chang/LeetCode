/*
 * @lc app=leetcode id=2147 lang=cpp
 *
 * [2147] Number of Ways to Divide a Long Corridor
 */

// @lc code=start
class Solution
{
public:
    int mod = 1e9 + 7;
    int numberOfWays(string corridor)
    {
        int n = corridor.size();
        int prev = -1, cnt = 0, ans = 1;
        for (int i = 0; i < n; ++i)
        {
            if (corridor[i] == 'S')
            {
                ++cnt;
                if (cnt >= 3 && cnt % 2 == 1)
                    ans = static_cast<long long>(ans) * (i - prev) % mod;

                prev = i;
            }
        }
        if (cnt < 2 || cnt & 1)
            ans = 0;

        return ans;
    }
};
// @lc code=end

// Official Solution

// Note: DP