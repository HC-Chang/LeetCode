/*
 * @lc app=leetcode id=1848 lang=c
 *
 * [1848] Minimum Distance to the Target Element
 */

// @lc code=start
int getMinDistance(int *nums, int numsSize, int target, int start)
{
    int dis = numsSize;
    for (int i = 0; i < numsSize; i++)
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
// @lc code=end
