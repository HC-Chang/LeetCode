/*
 * @lc app=leetcode id=1493 lang=c
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
int longestSubarray(int *nums, int numsSize)
{
    int l = 0, r = 0;
    int k = 1;
    while (r < numsSize)
    {
        if (nums[r++] == 0)
            --k;
        if (k < 0 && nums[l++] == 0)
            ++k;
    }
    return r - l - 1;
}
// @lc code=end
