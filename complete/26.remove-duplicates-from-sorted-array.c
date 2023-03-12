/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
int removeDuplicates(int *nums, int numsSize)
{
    int index = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > nums[index])
            nums[++index] = nums[i];
    }
    return index + 1;
}
// @lc code=end
