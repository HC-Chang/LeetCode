/*
 * @lc app=leetcode id=401 lang=c
 *
 * [401] Binary Watch
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **readBinaryWatch(int turnedOn, int *returnSize)
{
    *returnSize = 0;
    if (turnedOn > 8)
        return NULL;

    char **ans = malloc(720 * sizeof(char *));
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (turnedOn == __builtin_popcount(i) + __builtin_popcount(j))
            {
                ans[(*returnSize)] = malloc(6 * sizeof(char));
                sprintf(ans[(*returnSize)++], "%d:%02d", i, j);
            }
        }
    }
    return ans;
}
// @lc code=end

// Note: back tracking + bit manipulation