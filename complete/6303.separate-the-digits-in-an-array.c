/*
 * @lc app=leetcode id=6303 lang=c
 *
 * [6303] Separate the Digits in an Array
 */

// Difficulty:Easy

// Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.
// To separate the digits of an integer is to get all the digits it has in the same order.
// For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].

// Constraints:
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 105

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *separateDigits(int *nums, int numsSize, int *returnSize)
{
    int *arr = calloc(10000, sizeof(int));
    int tmp[10000] = {0};
    *returnSize = numsSize;
    int index = 0;
    int tmp_index = 0;
    for (int i = 0; i < numsSize; i++)
    {
        tmp_index = 0;
        while (nums[i])
        {
            tmp[tmp_index++] = nums[i] % 10;
            nums[i] /= 10;
        }
        for (int j = 0; j < tmp_index; j++)
            arr[index++] = tmp[tmp_index - 1 - j];
    }
    *returnSize = index;
    return arr;
}

// @lc code=end