/*
 * @lc app=leetcode id=767 lang=c
 *
 * [767] Reorganize String
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
char *reorganizeString(char *s)
{
    int n = strlen(s);
    int idx = 1;
    int cnt[26] = {0};
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a'] += 100;
    for (int i = 0; i < 26; i++)
        cnt[i] += i;
    qsort(&cnt, 26, sizeof(int), sort);

    int t;
    char ch;
    for (int i = 0; i < 26; i++)
    {
        t = cnt[i] / 100;
        ch = 'a' + (cnt[i] % 100);
        if (t > (n + 1) / 2)
            return "";
        for (int j = 0; j < t; j++)
        {
            if (idx >= n)
                idx = 0;
            s[idx] = ch;
            idx += 2;
        }
    }
    return s;
}
// @lc code=end

// Note: hash table . greedy . sorting . heap