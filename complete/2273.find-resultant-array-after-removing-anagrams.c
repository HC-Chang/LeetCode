/*
 * @lc app=leetcode id=2273 lang=c
 *
 * [2273] Find Resultant Array After Removing Anagrams
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int sort(const void *a, const void *b) { return *(char *)a - *(char *)b; }

char **removeAnagrams(char **words, int wordsSize, int *returnSize)
{
    char **ans = malloc(wordsSize * sizeof(char *));
    *returnSize = 0;
    char last[101] = {0};
    char tmp[101] = {0};
    int len;
    for (int i = 0; i < wordsSize; i++)
    {
        len = strlen(words[i]);
        memcpy(tmp, words[i], sizeof(char) * len + 1);
        qsort(tmp, len, sizeof(char), sort);
        if (strcmp(last, tmp) != 0)
            ans[(*returnSize)++] = words[i];
        memcpy(last, tmp, sizeof(char) * strlen(tmp) + 1);
    }

    return ans;
}
// @lc code=end

// Note: hash table + sorting