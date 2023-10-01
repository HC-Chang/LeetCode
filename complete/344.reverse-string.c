/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */

// @lc code=start
void swap(int i, int j, char *s)
{
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
}

void reverseString(char *s, int sSize)
{
    for (int i = 0; i < sSize / 2; i++)
        swap(i, sSize - 1 - i, s);
}
// @lc code=end
