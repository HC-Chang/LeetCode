/*
 * @lc app=leetcode id=238 lang=c
 *
 * [238] Product of Array Except Self
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;

    int product = 1;
    int zero_count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
            ++zero_count;
        else
            product *= nums[i];
    }

    if (zero_count >= 2)
    {
        for (int i = 0; i < numsSize; i++)
            nums[i] = 0;
        return nums;
    }

    if (zero_count == 1)
    {
        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i] == 0)
                nums[i] = product;
            else
                nums[i] = 0;
        }
        return nums;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
            nums[i] = product;
        else
            nums[i] = product / nums[i];
    }

    return nums;
}
// @lc code=end
// NOTE 考慮 0 出現的次數
// 出現 0 次:     全部不為 0
// 出現 1 次:     一個不為 0
// 出現 2 次以上: 全部為 0

// NOTE Another Solution
// 由陣列右到左做乘積 r[left, ..., right]