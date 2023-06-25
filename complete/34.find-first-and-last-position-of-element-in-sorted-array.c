/*
 * @lc app=leetcode id=34 lang=c
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int bin_search_left(int *arr, int arr_size, int target)
{
    int left = 0;
    int right = arr_size;
    int middle;
    while (left < right)
    {
        middle = left + (right - left) / 2;
        if (target > arr[middle])
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *ret = malloc(*returnSize * sizeof(int));
    ret[0] = -1;
    ret[1] = -1;
    int left = bin_search_left(nums, numsSize, target);
    if (left == numsSize || nums[left] != target)
        return ret;
    int right = bin_search_left(nums, numsSize, target + 1) - 1;
    ret[0] = left;
    ret[1] = right;
    return ret;
}
// @lc code=end

// Note: binary search