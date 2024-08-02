/*
 * @lc app=leetcode id=2134 lang=c
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
int minSwaps(int *nums, int numsSize)
{
    int minimumSwaps = INT_MAX;
    int totalOnes = 0;
    for (int i = 0; i < numsSize; i++)
        totalOnes += nums[i];

    int onesCount = nums[0];
    int end = 0;

    for (int start = 0; start < numsSize; ++start)
    {
        if (start != 0)
            onesCount -= nums[start - 1];

        while (end - start + 1 < totalOnes)
        {
            end++;
            onesCount += nums[end % numsSize];
        }

        minimumSwaps = fmin(minimumSwaps, totalOnes - onesCount);
    }

    return minimumSwaps;
}
// @lc code=end

// Note: sliding window

// Official Solution