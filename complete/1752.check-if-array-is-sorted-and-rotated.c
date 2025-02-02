/*
 * @lc app=leetcode id=1752 lang=c
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
bool check(int *nums, int numsSize)
{
    int min_val = INT_MAX;
    int start = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < min_val)
        {
            min_val = nums[i];
            start = i;
        }
    }

    while (numsSize > 0 && nums[(start - 1 + numsSize) % numsSize] == nums[(start) % numsSize])
    {
        start = (start - 1 + numsSize) % numsSize;
        numsSize--;
    }

    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[(start + 1 + i) % numsSize] - nums[(start + i) % numsSize] < 0)
            return false;
    }

    return true;
}
// @lc code=end
