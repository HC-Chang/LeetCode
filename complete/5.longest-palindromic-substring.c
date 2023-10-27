/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
char *longestPalindrome(char *s)
{
    int size = strlen(s);

    if (size == 0 || size == 1)
        return s;

    int dp[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            dp[i][j] = 1;

    int maxLen = 0;
    int start = size - 1;
    int end = start;

    for (int i = 1; i < size; i++)
    {
        for (int j = 0, k = i; k < size; j++, k++)
        {
            if (s[j] == s[k] && dp[j + 1][k - 1])
            {
                if (maxLen < k - j + 1)
                {
                    maxLen = k - j + 1;
                    start = j;
                    end = k;
                }
                dp[j][k] = dp[j + 1][k - 1];
            }
            else
                dp[j][k] = 0;
        }
    }

    s[end + 1] = 0;
    return s + start;
}

// @lc code=end

// Note: DP