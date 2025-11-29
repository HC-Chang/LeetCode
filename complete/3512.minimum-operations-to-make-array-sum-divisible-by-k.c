/*
 * @lc app=leetcode id=3512 lang=c
 *
 * [3512] Minimum Operations to Make Array Sum Divisible by K
 */

// @lc code=start
int minOperations(int *nums, int numsSize, int k)
{
    int tmp = 0;
    for (int i = 0; i < numsSize; i++)
        tmp += nums[i] % k;
    return tmp % k;
}
// @lc code=end

// Note: math