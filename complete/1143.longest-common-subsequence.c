/*
 * @lc app=leetcode id=1143 lang=c
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
// Solution 2:
int longestCommonSubsequence(char *text1, char *text2)
{
    int len1 = strlen(text1);
    int len2 = strlen(text2);

    int *dp = calloc(len2 + 1, sizeof(int));

    int prev;
    int tmp;
    for (int i = 1; i <= len1; i++)
    {
        prev = dp[0];
        for (int j = 1; j <= len2; j++)
        {
            tmp = dp[j];

            if (text1[i - 1] == text2[j - 1])
                dp[j] = prev + 1;
            else
                dp[j] = fmax(dp[j - 1], dp[j]);
            prev = tmp;
        }
    }
    int r = dp[len2];
    free(dp);

    return r;
}
// @lc code=end

// Solution 1:
// int longestCommonSubsequence(char *text1, char *text2)
// {
//     int len1 = strlen(text1);
//     int len2 = strlen(text2);

//     int **dp = calloc(len1 + 1, sizeof(int *));
//     for (int i = 0; i <= len1; i++)
//         dp[i] = calloc(len2 + 1, sizeof(int));

//     for (int i = 1; i <= len1; i++)
//     {
//         for (int j = 1; j <= len2; j++)
//         {
//             if (text1[i - 1] == text2[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             else
//                 dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
//     int r = dp[len1][len2];
//     for (int i = 0; i <= len1; i++)
//         free(dp[i]);
//     free(dp);

//     return r;
// }