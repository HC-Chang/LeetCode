/*
 * @lc app=leetcode id=3068 lang=c
 *
 * [3068] Find the Maximum Sum of Node Values
 */

// @lc code=start
long long maximumValueSum(int *nums, int numsSize, int k, int **edges, int edgesSize, int *edgesColSize)
{
    long long f0 = 0;
    long long f1 = LLONG_MIN;
    long long t;
    for (int i = 0; i < numsSize; i++)
    {
        t = fmax(f1 + nums[i], f0 + (nums[i] ^ k));
        f0 = fmax(f0 + nums[i], f1 + (nums[i] ^ k));
        f1 = t;
    }
    return f0;
}
// @lc code=end

// Note: greedy + bit manipulation