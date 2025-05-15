/*
 * @lc app=leetcode id=2900 lang=c
 *
 * [2900] Longest Unequal Adjacent Groups Subsequence I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **getLongestSubsequence(char **words, int wordsSize, int *groups, int groupsSize, int *returnSize)
{
    char **ans = malloc(wordsSize * sizeof(char *));
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        if (i == 0 || groups[i] != groups[i - 1])
            ans[(*returnSize)++] = words[i];
    }
    return ans;
}
// @lc code=end

// Note: DP + greedy