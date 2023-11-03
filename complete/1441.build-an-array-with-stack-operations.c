/*
 * @lc app=leetcode id=1441 lang=c
 *
 * [1441] Build an Array With Stack Operations
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **buildArray(int *target, int targetSize, int n, int *returnSize)
{
    int cur = 0;
    char **ans = malloc(200 * sizeof(char *));
    for (int i = 0; i < 200; i++)
        ans[i] = calloc(4, sizeof(char));
    int index = 0;
    for (int i = 0; i < targetSize; i++)
    {
        while (++cur < target[i])
        {
            ans[index++] = "Push";
            ans[index++] = "Pop";
        }
        ans[index++] = "Push";
    }
    *returnSize = index;

    return ans;
}
// @lc code=end

// Note: stack