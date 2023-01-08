/*
 * @lc app=leetcode id=125 lang=c
 *
 * [125] Valid Palindrome
 */

// @lc code=start
static bool is_mark(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return false;
    return true;
}
bool isPalindrome(char *s)
{
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right)
    {
        if (is_mark(s[left]))
        {
            left++;
            continue;
        }
        if (is_mark(s[right]))
        {
            right--;
            continue;
        }
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        left++;
        right--;
    }

    return true;
}
// @lc code=end
