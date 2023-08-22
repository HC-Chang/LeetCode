/*
 * @lc app=leetcode id=2194 lang=c
 *
 * [2194] Cells in a Range on an Excel Sheet
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **cellsInRange(char *s, int *returnSize)
{
    int w = s[3] - s[0] + 1;
    int h = s[4] - s[1] + 1;
    *returnSize = w * h;
    char **r = malloc(w * h * sizeof(char *));
    for (int i = 0; i < (*returnSize); i++)
        r[i] = calloc(3, sizeof(char));

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
            sprintf(r[i * h + j], "%c%c", s[0] + i, s[1] + j);
    }
    return r;
}
// @lc code=end
