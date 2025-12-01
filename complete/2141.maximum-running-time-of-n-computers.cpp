/*
 * @lc app=leetcode id=2141 lang=cpp
 *
 * [2141] Maximum Running Time of N Computers
 */

// @lc code=start
class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        int batteriesSize = batteries.size();
        if (batteriesSize < n)
            return 0;

        sort(batteries.begin(), batteries.end(), greater<int>());
        long long sum = 0;
        for (int i = 0; i < batteriesSize; i++)
            sum += batteries[i];
        for (int i = 0; i < batteriesSize; i++)
        {
            if (batteries[i] <= sum / n)
                break;
            sum -= batteries[i];
            --n;
        }
        return sum / n;
    }
};
// @lc code=end
