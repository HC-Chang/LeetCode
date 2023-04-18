/*
 * @lc app=leetcode id=1768 lang=c
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start

char *mergeAlternately(char *word1, char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int max_len = len1 > len2 ? len1 : len2;
    char *str = malloc((len1 + len2 + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < max_len; i++)
    {
        if (i < len1)
            str[index++] = word1[i];
        if (i < len2)
            str[index++] = word2[i];
    }

    str[index] = '\0';
    return str;
}
// @lc code=end
