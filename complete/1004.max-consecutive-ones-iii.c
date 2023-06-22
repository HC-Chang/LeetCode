/*
 * @lc app=leetcode id=1004 lang=c
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
int longestOnes(int *nums, int numsSize, int k)
{
    int l = 0, r = 0;
    while (r < numsSize)
    {
        if (nums[r++] == 0)
            --k;
        if (k < 0 && nums[l++] == 0)
            ++k;
    }
    return r - l;
}
// @lc code=end
