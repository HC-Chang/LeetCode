/*
 * @lc app=leetcode id=1701 lang=cpp
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double wait = 0;
        double curr = 0;

        for (auto c : customers)
        {
            curr = max(curr, (double)c[0]) + c[1];
            wait += curr - c[0];
        }

        return wait / customers.size();
    }
};
// @lc code=end

// Note: simulation