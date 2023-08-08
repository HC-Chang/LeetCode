/*
 * @lc app=leetcode id=1071 lang=c
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
char *gcdOfStrings(char *str1, char *str2)
{
    char *l;
    char *s;
    if (strlen(str1) > strlen(str2))
    {
        l = str1;
        s = str2;
    }
    else
    {
        l = str2;
        s = str1;
    }

    if (!strcmp(l, s))
        return s;

    int s_len = strlen(s);
    if (strncmp(l, s, s_len) != 0)
        return "";

    return gcdOfStrings(l + s_len, s);
}
// @lc code=end


// Note: GCD