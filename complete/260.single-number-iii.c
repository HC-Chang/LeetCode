/*
 * @lc app=leetcode id=260 lang=c
 *
 * [260] Single Number III
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *singleNumber(int *nums, int numsSize, int *returnSize)
{
    int xor2no = 0;
    for (int i = 0; i < numsSize; i++)
        xor2no ^= nums[i];

    unsigned int lowestBit = xor2no & -(unsigned int)xor2no;

    *returnSize = 2;
    int *tmps = calloc(2, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        if ((lowestBit & nums[i]) == 0)
            tmps[0] ^= nums[i];
        else
            tmps[1] ^= nums[i];
    }

    return tmps;
}
// @lc code=end

// Note: bit manipulation