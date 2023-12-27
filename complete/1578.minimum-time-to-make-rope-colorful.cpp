/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int sum = neededTime[0];
        int tmp_max = neededTime[0];
        int min_cost = 0;
        int n = neededTime.size();
        for (int i = 1; i < n; i++)
        {
            if (colors[i] == colors[i - 1])
            {
                sum += neededTime[i];
                if (neededTime[i] > tmp_max)
                    tmp_max = neededTime[i];
            }
            else
            {
                min_cost += sum - tmp_max;
                sum = neededTime[i];
                tmp_max = neededTime[i];
            }
        }
        if (colors[n - 1] == colors[n - 2])
            min_cost += sum - tmp_max;

        return min_cost;
    }
};
// @lc code=end
