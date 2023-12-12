/*
 * @lc app=leetcode id=1464 lang=c
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
int maxProduct(int *nums, int numsSize)
{
    int index = nums[0] > nums[1] ? 1 : 0;
    for (int i = 2; i < numsSize; i++)
    {
        if (nums[i] > nums[index])
        {
            nums[index] = nums[i];
            index = nums[0] > nums[1] ? 1 : 0;
        }
    }
    return (nums[0] - 1) * (nums[1] - 1);
}
// @lc code=end
