/*
 * @lc app=leetcode id=1218 lang=c
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

// @lc code=start
int longestSubsequence(int *arr, int arrSize, int difference)
{
    int max = 0;
    int dp[200000] = {1};
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] += 100000;
        dp[arr[i]] = dp[arr[i] - difference] + 1;
        if (dp[arr[i]] > max)
            max = dp[arr[i]];
    }
    return max;
}
// @lc code=end
