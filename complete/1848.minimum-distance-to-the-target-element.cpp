/*
 * @lc app=leetcode id=1848 lang=cpp
 *
 * [1848] Minimum Distance to the Target Element
 */

// @lc code=start
class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int dis = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                if (abs(i - start) < dis)
                    dis = abs(i - start);
                else
                    return dis;
            }
        }
        return dis;
    }
};
// @lc code=end
