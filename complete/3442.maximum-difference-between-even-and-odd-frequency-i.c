/*
 * @lc app=leetcode id=3442 lang=c
 *
 * [3442] Maximum Difference Between Even and Odd Frequency I
 */

// @lc code=start
int maxDifference(char *s)
{
    int cnts[26] = {0};
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        ++cnts[s[i] - 'a'];

    int maxs[2] = {INT_MIN, INT_MIN};
    int mins[2] = {INT_MAX, INT_MAX};

    for (int i = 0; i < 26; i++)
    {
        if (cnts[i] == 0)
            continue;
        if (cnts[i] > maxs[cnts[i] % 2])
            maxs[cnts[i] % 2] = cnts[i];
        if (cnts[i] < mins[cnts[i] % 2])
            mins[cnts[i] % 2] = cnts[i];
    }

    return fmax(mins[1] - maxs[0], maxs[1] - mins[0]);
}
// @lc code=end

// Note: hash table