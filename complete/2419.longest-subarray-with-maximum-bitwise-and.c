/*
 * @lc app=leetcode id=2419 lang=c
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
int longestSubarray(int *nums, int numsSize)
{
    int max_val = 0;
    int max_cnt = 0;
    int cnt = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (max_val < nums[i])
        {
            max_val = nums[i];
            cnt = 0;
            max_cnt = cnt;
        }

        if (max_val == nums[i])
        {
            cnt++;
            max_cnt = fmax(max_cnt, cnt);
        }
        else
            cnt = 0;
    }
    return max_cnt;
}
// @lc code=end

// Note: bit manipulation

// Official Solution