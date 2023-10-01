/*
 * @lc app=leetcode id=557 lang=c
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
void swap(int l, int r, char *s)
{
    char c = s[l];
    s[l] = s[r];
    s[r] = c;
}

char *reverseWords(char *s)
{
    int s_len = strlen(s);
    int l = 0;
    int r = 0;
    while (r < s_len)
    {
        while (s[r] != ' ' && r < s_len)
            r++;
        for (int i = 0; i < (r - l) / 2; i++)
            swap(l + i, r - 1 - i, s);
        r++;
        l = r;
    }
    return s;
}
// @lc code=end

// Note: two pointers