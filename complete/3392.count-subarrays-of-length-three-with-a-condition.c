/*
 * @lc app=leetcode id=3392 lang=c
 *
 * [3392] Count Subarrays of Length Three With a Condition
 */

// @lc code=start
int countSubarrays(int *nums, int numsSize)
{
    int cnt = 0;
    for (int i = 0; i < numsSize - 2; i++)
    {
        if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1])
            cnt++;
    }
    return cnt;
}
// @lc code=end
