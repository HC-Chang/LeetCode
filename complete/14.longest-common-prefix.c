/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
void lcp(char *s1, char *s2)
{
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int index = 0;
    while (index < len_s1 && index < len_s2)
    {
        if (s1[index] == s2[index])
            index++;
        else
            break;
    }
    s1[index] = '\0';
}

char *longestCommonPrefix(char **strs, int strsSize)
{
    char *s1 = strs[0];
    char *s2;
    for (int i = 1; i < strsSize; i++)
    {
        s2 = strs[i];
        lcp(s1, s2);
    }
    return s1;
}
// @lc code=end
