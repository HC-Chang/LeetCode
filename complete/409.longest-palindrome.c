/*
 * @lc app=leetcode id=409 lang=c
 *
 * [409] Longest Palindrome
 */

// @lc code=start
int longestPalindrome(char *s)
{
    int map[60] = {0};

    while (*s)
    {
        ++map[*s - 'A'];
        s++;
    }

    int r = 0;
    int temp_len;
    for (int i = 0; i < 60; ++i)
    {
        temp_len = map[i];
        if (map[i] % 2 == 1)
        {
            temp_len--;
        }

        r += temp_len;
        if (r % 2 == 0 && map[i] % 2 == 1)
        {
            r++;
        }
    }

    return r;
}
// @lc code=end
