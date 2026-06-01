/*
 * @lc app=leetcode id=2144 lang=cpp
 *
 * [2144] Minimum Cost of Buying Candies With Discount
 */

// @lc code=start
class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        sort(cost.begin(), cost.end(), greater<int>());
        int idx = 0;
        int ans = 0;
        for (auto &c : cost)
        {
            if (++idx == 3)
            {
                idx = 0;
                continue;
            }
            else
                ans += c;
        }
        return ans;
    }
};
// @lc code=end

// Note: sort