/*
 * @lc app=leetcode id=3432 lang=c
 *
 * [3432] Count Partitions with Even Sum Difference
 */

// @lc code=start
int countPartitions(int *nums, int numsSize)
{
    for (int i = 1; i < numsSize; i++)
        nums[i] += nums[i - 1];

    int cnt = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if ((nums[numsSize - 1] - 2 * nums[i]) % 2 == 0)
            cnt++;
    }
    return cnt;
}
// @lc code=end

// Note: math + prefix sum