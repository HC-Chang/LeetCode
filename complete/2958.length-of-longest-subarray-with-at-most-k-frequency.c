/*
 * @lc app=leetcode id=2958 lang=c
 *
 * [2958] Length of Longest Subarray With at Most K Frequency
 */

// @lc code=start
int maxSubarrayLength(int *nums, int numsSize, int k)
{
    int hash[4 * numsSize];
    memset(hash, 0, sizeof(hash));
    int max_cnt = 0;
    for (int i = 0, j = 0; i < numsSize; ++i)
    {
        ++hash[nums[i] % (4 * numsSize)];
        while (hash[nums[i] % (4 * numsSize)] > k)
        {
            --hash[nums[j++] % (4 * numsSize)];
        }
        max_cnt = fmax(max_cnt, i - j + 1);
    }
    return max_cnt;
}
// @lc code=end

// Note: hash table + sliding window