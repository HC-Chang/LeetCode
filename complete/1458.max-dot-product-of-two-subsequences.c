/*
 * @lc app=leetcode id=1458 lang=c
 *
 * [1458] Max Dot Product of Two Subsequences
 */

// @lc code=start
int maxDotProduct(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int dp[nums1Size][nums2Size];
    memset(dp, 0, nums1Size * nums2Size * sizeof(int));
    for (int i = 0; i < nums1Size; ++i)
    {
        for (int j = 0; j < nums2Size; ++j)
        {
            dp[i][j] = nums1[i] * nums2[j];
            if (i > 0 && j > 0)
                dp[i][j] += fmax(0, dp[i - 1][j - 1]);
            if (i > 0)
                dp[i][j] = fmax(dp[i][j], dp[i - 1][j]);
            if (j > 0)
                dp[i][j] = fmax(dp[i][j], dp[i][j - 1]);
        }
    }
    return dp[nums1Size - 1][nums2Size - 1];
}
// @lc code=end

// Note: DP
