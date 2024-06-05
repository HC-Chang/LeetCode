/*
 * @lc app=leetcode id=1002 lang=c
 *
 * [1002] Find Common Characters
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **commonChars(char **words, int wordsSize, int *returnSize)
{
    *returnSize = 0;
    int arr[26] = {0};
    int n;
    n = strlen(words[0]);
    for (int i = 0; i < n; i++)
        ++arr[words[0][i] - 'a'];

    int tmp[26];
    for (int i = 1; i < wordsSize; i++)
    {
        n = strlen(words[i]);
        memset(tmp, 0, sizeof(tmp));
        for (int j = 0; j < n; j++)
            ++tmp[words[i][j] - 'a'];
        for (int j = 0; j < 26; j++)
            arr[j] = fmin(arr[j], tmp[j]);
    }

    char **ans = malloc(100 * sizeof(char *));
    for (int i = 0; i < 100; i++)
        ans[i] = calloc(2, sizeof(char));
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < arr[i]; j++)
            ans[(*returnSize)++][0] = 'a' + i;
    }
    return ans;
}
// @lc code=end

// Note: hash table