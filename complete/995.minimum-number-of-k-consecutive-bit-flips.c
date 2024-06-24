/*
 * @lc app=leetcode id=995 lang=c
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 */

// @lc code=start
int minKBitFlips(int *nums, int numsSize, int k)
{
    int cnt = 0;
    int flipped = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (i >= k)
            flipped -= nums[i - k] / 2;
        if (flipped % 2 == nums[i])
        {
            if (i + k > numsSize)
                return -1;
            nums[i] += 2;
            ++flipped;
            ++cnt;
        }
    }
    return cnt;
}
// @lc code=end
