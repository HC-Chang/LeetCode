/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#define MAX(a, b) a >= b ? a : b

// 移動陣列
int maxSubArray(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return *nums;
    }

    int sum = 0;
    int max = *nums;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        max = MAX(max, sum);
        
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return max;
}
// @lc code=end
