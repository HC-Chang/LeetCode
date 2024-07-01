/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int cnt = 0;
        for (auto i : arr)
        {
            if (i % 2)
            {
                if (++cnt == 3)
                    return true;
            }
            else
                cnt = 0;
        }
        return false;
    }
};
// @lc code=end

// Note: array