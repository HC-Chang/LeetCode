/*
 * @lc app=leetcode id=1653 lang=c
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

// @lc code=start
int minimumDeletions(char *s)
{
    int n = strlen(s);
    int min_deletions = 0;
    int b_count = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'b')
            b_count++;
        else
            min_deletions = fmin(min_deletions + 1, b_count);
    }

    return min_deletions;
}
// @lc code=end

// Note: DP / stack