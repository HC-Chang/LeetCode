/*
 * @lc app=leetcode id=152 lang=c
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int maxProduct(int *nums, int numsSize)
{
    int max_product = nums[0];
    int *dp1 = malloc(numsSize * sizeof(int));
    int *dp2 = malloc(numsSize * sizeof(int));
    dp1[0] = nums[0];
    dp2[0] = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        dp1[i] = max(max(dp1[i - 1] * nums[i], dp2[i - 1] * nums[i]), nums[i]);
        dp2[i] = min(min(dp1[i - 1] * nums[i], dp2[i - 1] * nums[i]), nums[i]);
        max_product = max(max_product, dp1[i]);
    }
    free(dp1);
    free(dp2);
    return max_product;
}
// @lc code=end

// Note: DP