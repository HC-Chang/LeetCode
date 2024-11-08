/*
 * @lc app=leetcode id=1829 lang=c
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getMaximumXor(int *nums, int numsSize, int maximumBit, int *returnSize)
{
    int xor_product = 0;
    for (int i = 0; i < numsSize; i++)
        xor_product = xor_product ^ nums[i];

    *returnSize = numsSize;
    int *ans = malloc(numsSize * sizeof(int));

    int mask = (1 << maximumBit) - 1;

    for (int i = 0; i < numsSize; i++)
    {
        ans[i] = xor_product ^ mask;
        xor_product = xor_product ^ nums[numsSize - 1 - i];
    }

    return ans;
}
// @lc code=end

// Note: bit manipulation + prefix sum

// Official Solution