/*
 * @lc app=leetcode id=3014 lang=c
 *
 * [3014] Minimum Number of Pushes to Type Word I
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int minimumPushes(char *word)
{
    int v[26] = {0};
    while (*word)
        ++v[*word++ - 'a'];
    qsort(v, 26, sizeof(int), sort);
    int idx = 0;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (v[i] == 0)
            break;
        if (i % 8 == 0)
            idx++;
        ans += v[i] * idx;
    }

    return ans;
}
// @lc code=end

// Note: math + greedy