/*
 * @lc app=leetcode id=2419 lang=c
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
int longestSubarray(int *nums, int numsSize)
{
    int max = 0;
    int ans = 0;
    int cur = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
            cur = 0;
            ans = cur;
        }

        if (max == nums[i])
            cur++;
        else
            cur = 0;

        ans = fmax(ans, cur);
    }
    return ans;
}
// @lc code=end

// Note: bit manipulation

// Official Solution