/*
 * @lc app=leetcode id=438 lang=c
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *minWindow(char *s, char *t, int *returnSize)
{
    int s_len = strlen(s);
    int t_len = strlen(t);
    int left = 0;
    int right = 0;

    int start;
    int *r = calloc(s_len, sizeof(int));

    int s_valids[26] = {0};
    int t_valids[26] = {0};

    for (int i = 0; i < t_len; i++)
        t_valids[t[i] - 'a']++;

    for (int i = 0; i < s_len; i++)
    {
        if (i >= t_len)
        {
            start = s[i - t_len] - 'a';
            --s_valids[start];
        }
        s_valids[s[i] - 'a']++;
        if (!memcmp(s_valids, t_valids, 26 * sizeof(int)))
            r[(*returnSize)++] = i - t_len + 1;
    }

    return r;
}

int *findAnagrams(char *s, char *p, int *returnSize)
{
    int s_len = strlen(s);
    int p_len = strlen(p);
    *returnSize = 0;
    if (s_len < p_len)
        return NULL;

    int *r = minWindow(s, p, returnSize);

    return r;
}
// @lc code=end

// Sliding Window
