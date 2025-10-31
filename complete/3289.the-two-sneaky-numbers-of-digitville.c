/*
 * @lc app=leetcode id=3289 lang=c
 *
 * [3289] The Two Sneaky Numbers of Digitville
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getSneakyNumbers(int *nums, int numsSize, int *returnSize)
{
    int arr[101] = {0};
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (arr[nums[i]]++ == 1)
            nums[(*returnSize)++] = nums[i];
    }

    return nums;
}
// @lc code=end

// Note: hash table