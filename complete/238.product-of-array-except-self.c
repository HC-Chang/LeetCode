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
    int *r = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;

    // NOTE Solution 1:
    int zero_count = 0;
    int products = 1;
    int zero_index = -1;
    for (int i = 0; i < numsSize; i++)

    // NOTE Solution 2:
    // int zero_count = nums[0] == 0 ? 1 : 0;
    // int products = nums[0] == 0 ? 0 : nums[0];
    // int zero_index = nums[0] == 0 ? 0 : -1;
    // for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            if (zero_count == 0)
            {
                zero_index = i;
            }
            zero_count++;
            continue;
        }
        products *= nums[i];
    }

    if (zero_count == 0)
    {
        for (int i = 0; i < numsSize; i++)
        {
            r[i] = products / nums[i];
        }
    }
    else if (zero_count > 0 && zero_count < 2)
    {
        r[zero_index] = products;
    }

    return r;
}
// @lc code=end
// NOTE 考慮 0 出現的次數
// 出現 0 次:     全部不為 0
// 出現 1 次:     一個不為 0
// 出現 2 次以上: 全部為 0

// NOTE Another Solution
// 由陣列右到左做乘積 r[left, ..., right]