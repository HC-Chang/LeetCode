/*
 * @lc app=leetcode id=704 lang=c
 *
 * [704] Binary Search
 */

// @lc code=start
int search(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int middle;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (target == nums[middle])
            return middle;
        else if (target < nums[middle])
            right = middle - 1;
        else if (target > nums[middle])
            left = middle + 1;
    }
    return -1;
}
// @lc code=end
