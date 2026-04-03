/*
 * @lc app=leetcode id=541 lang=c
 *
 * [541] Reverse String II
 */

// @lc code=start
void reverse(char *s, int n)
{
    char tmp;
    for (int i = 0; i < n / 2; i++)
    {
        tmp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = tmp;
    }
}

char *reverseStr(char *s, int k)
{
    int n = strlen(s);
    for (int i = 0; i < n; i += 2 * k)
    {
        if (i + k < n)
            reverse(s + i, k);
        else
            reverse(s + i, n - i);
    }

    return s;
}
// @lc code=end

// Note: two pointers