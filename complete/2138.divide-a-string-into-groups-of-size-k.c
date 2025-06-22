/*
 * @lc app=leetcode id=2138 lang=c
 *
 * [2138] Divide a String Into Groups of Size k
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **divideString(char *s, int k, char fill, int *returnSize)
{
    int n = strlen(s);
    *returnSize = n / k;
    if (n % k)
        ++*returnSize;

    char **ans;
    int idx_ans = 0;
    ans = malloc(*returnSize * sizeof(char *));
    for (int i = 0; i < n; i += k)
    {
        char *tmp = calloc(k + 1, sizeof(char));
        strncpy(tmp, s + i, k);
        ans[idx_ans++] = tmp;
    }
    while (n % k)
        ans[idx_ans - 1][n++ % k] = fill;

    return ans;
}
// @lc code=end

// Note: simulation