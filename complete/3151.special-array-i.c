/*
 * @lc app=leetcode id=3151 lang=c
 *
 * [3151] Special Array I
 */

// @lc code=start
bool isArraySpecial(int *nums, int numsSize)
{
    if (numsSize < 2)
        return true;
    int tmp1 = nums[0] % 2;
    int tmp2;
    for (int i = 1; i < numsSize; i++)
    {
        tmp2 = nums[i] % 2;
        if (tmp1 == tmp2)
            return false;
        tmp1 = tmp2;
    }
    return true;
}
// @lc code=end
