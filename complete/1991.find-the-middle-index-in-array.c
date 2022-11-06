/*
 * @lc app=leetcode id=1991 lang=c
 *
 * [1991] Find the Middle Index in Array
 */

// @lc code=start
int findMiddleIndex(int *nums, int numsSize)
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
// Note: 
// This question is the same as 724: https://leetcode.com/problems/find-pivot-index/

