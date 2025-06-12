/*
 * @lc app=leetcode id=3423 lang=c
 *
 * [3423] Maximum Difference Between Adjacent Elements in a Circular Array
 */

// @lc code=start
int maxAdjacentDistance(int *nums, int numsSize)
{
    int max_dis = abs(nums[0] - nums[numsSize - 1]);
    for (int i = 0; i < numsSize - 1; i++)
        max_dis = fmax(abs(nums[i + 1] - nums[i]), max_dis);
    return max_dis;
}
// @lc code=end
