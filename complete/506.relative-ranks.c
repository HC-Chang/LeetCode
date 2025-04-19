/*
 * @lc app=leetcode id=506 lang=c
 *
 * [506] Relative Ranks
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int score;
    char *label;
} DATA;

int sort(const void *a, const void *b) { return ((DATA *)a)->score < ((DATA *)b)->score; }

char **findRelativeRanks(int *score, int scoreSize, int *returnSize)
{
    *returnSize = scoreSize;

    char **ans = malloc(scoreSize * sizeof(char *));
    DATA *d = malloc(scoreSize * sizeof(DATA));
    for (int i = 0; i < scoreSize; i++)
    {
        ans[i] = calloc(13, sizeof(char));
        d[i].score = score[i];
        d[i].label = ans[i];
    }
    qsort(d, scoreSize, sizeof(DATA), sort);
    if (scoreSize > 0)
        sprintf(d[0].label, "%s", "Gold Medal");
    if (scoreSize > 1)
        sprintf(d[1].label, "%s", "Silver Medal");
    if (scoreSize > 2)
        sprintf(d[2].label, "%s", "Bronze Medal");
    for (int i = 3; i < scoreSize; i++)
        sprintf(d[i].label, "%i", i + 1);

    return ans;
}
// @lc code=end

// Note: sorting + min heap