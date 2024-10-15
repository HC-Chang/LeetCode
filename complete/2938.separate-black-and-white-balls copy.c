/*
 * @lc app=leetcode id=2938 lang=c
 *
 * [2938] Separate Black and White Balls
 */

// @lc code=start
long long minimumSteps(char *s)
{
    long long swap_cnt = 0;
    int black_cnt = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            swap_cnt += (long long)black_cnt;
        else
            black_cnt++;
    }

    return swap_cnt;
}
// @lc code=end

// Note: greedy

// Official Solution