/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */

// @lc code=start
// Solution 2:

void reverseString(char *s, int sSize)
{
    char c;
    int l = 0;
    int r = sSize - 1;
    while (l < r)
    {
        c = s[l];
        s[l++] = s[r];
        s[r--] = c;
    }
}
// @lc code=end

// Note: two pointers

// Solution 1:

// void reverseString(char *s, int sSize)
// {
//     char c;
//     int n = sSize / 2;
//     for (int i = 0; i < n; i++)
//     {
//         c = s[i];
//         s[i] = s[sSize - 1 - i];
//         s[sSize - 1 - i] = c;
//     }
// }