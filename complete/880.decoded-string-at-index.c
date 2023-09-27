/*
 * @lc app=leetcode id=880 lang=c
 *
 * [880] Decoded String at Index
 */

// @lc code=start
bool is_digit(char c)
{
    return (c >= '0' && c <= '9') ? true : false;
}

char *decodeAtIndex(char *s, int k)
{
    long size = 0;
    int n = strlen(s);
    char *c = calloc(2, sizeof(char));

    for (int i = 0; i < n; i++)
    {
        c[0] = s[i];
        if (is_digit(c[0]))
            size *= c[0] - '0';
        else
            size++;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        c[0] = s[i];
        k %= size;
        if (k == 0 && !is_digit(c[0]))
            return c;
        if (is_digit(c[0]))
            size /= c[0] - '0';
        else
            size--;
    }
    return "";
}
// @lc code=end

// Note: stack