/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start
char *addBinary(char *a, char *b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    char *r = calloc(max_len + 1, sizeof(char));

    r[max_len] = '\0';

    int i;
    int carry = 0;
    for (i = 0; i < max_len; i++)
    {
        if (len_a)
            carry += a[--len_a] - '0';
        if (len_b)
            carry += b[--len_b] - '0';
        r[max_len - 1 - i] = (carry & 1) + '0';
        carry >>= 1;
    }
    if (carry == 1)
    {
        r = (char *)realloc(r, max_len + 2);
        for (i = max_len; i >= 0; i--)
            r[i + 1] = r[i];

        r[0] = '1';
    }

    return r;
}
// @lc code=end
