/*
 * @lc app=leetcode id=724 lang=c
 *
 * [724] Find Pivot Index
 */

// @lc code=start
int pivotIndex(int *nums, int numsSize)
{
    int left_sum = 0;
    int right_sum = 0;

    for (int i = 0; i < numsSize; i++)
    {
        right_sum += nums[i];
    }

    for (int i = 0; i < numsSize; i++)
    {
        right_sum -= nums[i];
        if (left_sum == right_sum)
            return i;
        left_sum += nums[i];
    }

    return -1;
}
// @lc code=end
