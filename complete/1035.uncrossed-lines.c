/*
 * @lc app=leetcode id=1035 lang=c
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
int max(int a, int b) { return a > b ? a : b; }
int maxUncrossedLines(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int **dp = malloc(nums1Size * sizeof(int *));
    dp[0] = calloc(nums2Size, sizeof(int));
    dp[0][0] = (nums1[0] == nums2[0] ? 1 : 0);
    for (int i = 1; i < nums1Size; i++)
    {
        dp[i] = calloc(nums2Size, sizeof(int));
        dp[i][0] = (nums1[i] == nums2[0] ? 1 : dp[i - 1][0]);
    }

    for (int i = 1; i < nums2Size; i++)
        dp[0][i] = (nums1[0] == nums2[i] ? 1 : dp[0][i - 1]);

    for (int x = 1; x < nums1Size; x++)
    {
        for (int y = 1; y < nums2Size; y++)
        {
            if (nums1[x] == nums2[y])
                dp[x][y] = dp[x - 1][y - 1] + 1;
            else
                dp[x][y] = max(max(dp[x][y - 1], dp[x - 1][y]), dp[x - 1][y - 1]);
        }
    }

    int r = dp[nums1Size - 1][nums2Size - 1];
    for (int i = 0; i < nums1Size; i++)
        free(dp[i]);
    free(dp);
    return r;
}

// @lc code=end
