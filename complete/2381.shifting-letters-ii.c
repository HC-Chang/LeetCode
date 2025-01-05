/*
 * @lc app=leetcode id=2381 lang=c
 *
 * [2381] Shifting Letters II
 */

// @lc code=start
char *shiftingLetters(char *s, int **shifts, int shiftsSize, int *shiftsColSize)
{
    int n = strlen(s);
    char diff[n];
    memset(diff, 0, sizeof(diff));
    for (int i = 0; i < shiftsSize; i++)
    {
        if (shifts[i][2] == 0)
            shifts[i][2] = -1;
        diff[shifts[i][0]] += shifts[i][2];
        if (shifts[i][1] + 1 < n)
            diff[shifts[i][1] + 1] -= shifts[i][2];
    }

    int diff_cache = 0;
    for (int i = 0; i < n; i++)
    {
        diff_cache += diff[i];
        while (diff_cache < 0)
            diff_cache += 26;
        s[i] = 'a' + (s[i] - 'a' + diff_cache) % 26;
    }
    return s;
}
// @lc code=end

// Note: prefix sum