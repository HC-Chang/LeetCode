/*
 * @lc app=leetcode id=459 lang=c
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
bool repeatedSubstringPattern(char *s)
{
    int len_s = strlen(s);
    char *t = malloc(2 * len_s-1);
    strcpy(t, s + 1);
    strncat(t, s, len_s - 1);
    if (strstr(t, s))
        return true;
    return false;
}
// @lc code=end

// Official Solution
