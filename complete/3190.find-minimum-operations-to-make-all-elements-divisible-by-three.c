/*
 * @lc app=leetcode id=3190 lang=c
 *
 * [3190] Find Minimum Operations to Make All Elements Divisible by Three
 */

// @lc code=start
int minimumOperations(int *nums, int numsSize)
{
    int cnt = 0;
    for (int i = 0; i < numsSize; i++)
        cnt += nums[i] % 3 == 0 ? 0 : 1;
    return cnt;
}
// @lc code=end

// Note: math