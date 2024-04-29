/*
 * @lc app=leetcode id=2997 lang=c
 *
 * [2997] Minimum Number of Operations to Make Array XOR Equal to K
 */

// @lc code=start
int minOperations(int *nums, int numsSize, int k)
{
    for (int i = 1; i < numsSize; i++)
        nums[0] ^= nums[i];

    int cnt = 0;
    while (nums[0] || k)
    {
        cnt += ((nums[0] & 1) != (k & 1));
        nums[0] >>= 1;
        k >>= 1;
    }
    return cnt;
}
// @lc code=end

// Note: bit manipulation