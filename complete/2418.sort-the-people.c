/*
 * @lc app=leetcode id=2418 lang=c
 *
 * [2418] Sort the People
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int idx;
    int h;
} DATA;

int sort(const void *a, const void *b) { return ((DATA *)b)->h - ((DATA *)a)->h; }

char **sortPeople(char **names, int namesSize, int *heights, int heightsSize,
                  int *returnSize)
{
    int n = namesSize;

    DATA d[n];
    for (int i = 0; i < n; i++)
    {
        d[i].idx = i;
        d[i].h = heights[i];
    }

    qsort(d, n, sizeof(DATA), sort);

    char **ans = malloc(n * sizeof(char *));
    *returnSize = n;
    for (int i = 0; i < n; i++)
        ans[i] = names[d[i].idx];
    return ans;
}
// @lc code=end

// Note: hash table + sorting