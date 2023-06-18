/*
 * @lc app=leetcode id=713 lang=c
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
int numSubarrayProductLessThanK(int *nums, int numsSize, int k)
{
    if (k <= 1)
        return 0;

    int count = 0;
    unsigned int tmp = 1;
    int left = 0;
    int right = 0;
    while (right < numsSize)
    {
        tmp *= nums[right];
        while (tmp >= k)
            tmp /= nums[left++];
        count += right - left + 1;
        right++;
    }

    return count;
}
// @lc code=end

// Note: Sliding Window