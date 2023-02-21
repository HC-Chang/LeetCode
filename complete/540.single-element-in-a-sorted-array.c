/*
 * @lc app=leetcode id=540 lang=c
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
int singleNonDuplicate(int *nums, int numsSize)
{
    // Solution 2: Binary Search

    int left = 0;
    int right = numsSize - 1;
    int middle;
    while (left < right)
    {
        middle = left + (right - left) / 2;
        if (middle % 2 == 1)
            middle--;
        if (nums[middle] == nums[middle + 1])
            left += 2;
        else
            right = middle;
    }
    return nums[left];
}
// @lc code=end

// Solution 1: XOR
// int singleNonDuplicate(int *nums, int numsSize)
// {
//     int r = nums[0];
//     for (int i = 1; i < numsSize; i++)
//         r ^= nums[i];
//     return r;
// }