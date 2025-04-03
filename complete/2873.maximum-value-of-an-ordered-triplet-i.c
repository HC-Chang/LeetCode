/*
 * @lc app=leetcode id=2873 lang=c
 *
 * [2873] Maximum Value of an Ordered Triplet I
 */

// @lc code=start
long long maximumTripletValue(int *nums, int numsSize)
{
    long long max_val = 0;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            for (int k = j + 1; k < numsSize; k++)
                max_val =
                    fmax(max_val, (long long)(nums[i] - nums[j]) * nums[k]);
        }
    }
    return max_val;
}
// @lc code=end
