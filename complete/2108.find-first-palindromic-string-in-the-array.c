/*
 * @lc app=leetcode id=2108 lang=c
 *
 * [2108] Find First Palindromic String in the Array
 */

// @lc code=start
bool is_palindromic(char *s)
{
    int l = 0;
    int r = strlen(s) - 1;
    while (l < r)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

char *firstPalindrome(char **words, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++)
    {
        if (is_palindromic(words[i]))
            return words[i];
    }
    return "";
}
// @lc code=end

// Note: two pointers