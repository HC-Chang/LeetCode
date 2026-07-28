/*
 * @lc app=leetcode id=3517 lang=c
 *
 * [3517] Smallest Palindromic Rearrangement I
 */

// @lc code=start
char *smallestPalindrome(char *s)
{
    int arr[26] = {0};
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        ++arr[s[i] - 'a'];

    char tmp = ' ';
    int idx = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < arr[i] / 2; j++)
            s[idx++] = 'a' + i;
        if (arr[i] % 2 == 1)
            tmp = 'a' + i;
    }
    int id = idx;
    if (tmp != ' ')
        s[idx++] = tmp;
    for (int i = id - 1; i >= 0; i--)
        s[idx++] = s[i];
    s[idx] = '\0';
    return s;
}
// @lc code=end

// Note: sorting