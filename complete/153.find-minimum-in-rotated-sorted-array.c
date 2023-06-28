/*
 * @lc app=leetcode id=153 lang=c
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
int findMin(int *nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] <= nums[numsSize - 1])
            right = mid;
        else
            left = mid + 1;
    }
    return nums[left];
}
// @lc code=end

// Note: binary search