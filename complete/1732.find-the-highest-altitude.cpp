/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int h = 0;
        int ans = 0;
        for (auto &g : gain)
        {
            h += g;
            if (g > 0 && h > ans)
                ans = h;
        }
        return ans;
    }
}; // @lc code=end
