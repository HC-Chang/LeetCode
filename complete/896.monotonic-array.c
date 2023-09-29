/*
 * @lc app=leetcode id=896 lang=c
 *
 * [896] Monotonic Array
 */

// @lc code=start
bool isMonotonic(int *nums, int numsSize)
{
    if (numsSize <= 2)
        return true;
    int PN;
    int i = 0;
    while (++i < numsSize)
    {
        if (nums[i] - nums[i - 1] != 0)
        {
            PN = (nums[i] - nums[i - 1]) > 0 ? 1 : -1;
            break;
        }
    }

    for (i++; i < numsSize; i++)
    {
        if (PN * (nums[i] - nums[i - 1]) < 0)
            return false;
    }
    return true;
}
// @lc code=end
