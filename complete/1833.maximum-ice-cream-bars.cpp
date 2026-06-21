/*
 * @lc app=leetcode id=1833 lang=cpp
 *
 * [1833] Maximum Ice Cream Bars
 */

// @lc code=start
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for (auto &c : costs)
        {
            if (coins >= c)
            {
                coins -= c;
                cnt++;
                if (coins <= 0)
                    break;
            }
        }

        return cnt;
    }
};
// @lc code=end

// Note: sort