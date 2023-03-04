/*
 * @lc app=leetcode id=2444 lang=c
 *
 * [2444] Count Subarrays With Fixed Bounds
 */

// @lc code=start
#define min(a, b) (a < b ? a : b)

long long countSubarrays(int *nums, int numsSize, int minK, int maxK)
{
    long long count = 0;
    int prev_min = -1, prev_max = -1, boundary = -1;
    int tmp;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < minK || nums[i] > maxK)
        {
            boundary = i;
            continue;
        }

        if (nums[i] == minK)
            prev_min = i;
        if (nums[i] == maxK)
            prev_max = i;
        tmp = min(prev_min, prev_max) - boundary;
        if (tmp > 0)
            count += tmp;
    }

    return count;
}

// @lc code=end
