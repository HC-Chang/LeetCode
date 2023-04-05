/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

// @lc code=start
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int stack[10];
    int index = 0;
    while (x)
    {
        stack[index++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < index / 2; i++)
    {
        if (stack[i] != stack[index - 1 - i])
            return false;
    }
    return true;
}
// @lc code=end
