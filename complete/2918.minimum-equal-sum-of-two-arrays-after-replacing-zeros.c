/*
 * @lc app=leetcode id=2918 lang=c
 *
 * [2918] Minimum Equal Sum of Two Arrays After Replacing Zeros
 */

// @lc code=start
long long minSum(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    long long sum1 = {0};
    long long sum2 = {0};
    int z_cnt1 = {0};
    int z_cnt2 = {0};
    for (int i = 0; i < nums1Size; i++)
    {
        if (nums1[i] == 0)
            ++z_cnt1;
        else
            sum1 += nums1[i];
    }
    for (int i = 0; i < nums2Size; i++)
    {
        if (nums2[i] == 0)
            ++z_cnt2;
        else
            sum2 += nums2[i];
    }

    if ((z_cnt1 == 0 && sum2 + z_cnt2 > sum1) || (z_cnt2 == 0 && sum1 + z_cnt1 > sum2))
        return -1;

    return fmax(sum1 + z_cnt1, sum2 + z_cnt2);
}
// @lc code=end

// Note: greedy