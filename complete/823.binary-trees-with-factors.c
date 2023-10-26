/*
 * @lc app=leetcode id=823 lang=c
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int numFactoredBinaryTrees(int *arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), sort);
    long long *dp = (long long *)malloc(arrSize * sizeof(long long));
    long long res = 0, mod = 1e9 + 7;
    for (int i = 0; i < arrSize; i++)
    {
        dp[i] = 1;
        for (int left = 0, right = i - 1; left <= right; left++)
        {
            while (left <= right && (long long)arr[left] * arr[right] > arr[i])
                right--;

            if (left <= right && (long long)arr[left] * arr[right] == arr[i])
            {
                if (left == right)
                    dp[i] = (dp[i] + dp[left] * dp[right]) % mod;
                else
                    dp[i] = (dp[i] + dp[left] * dp[right] * 2) % mod;
            }
        }
        res = (res + dp[i]) % mod;
    }
    free(dp);
    return res;
}
// @lc code=end
