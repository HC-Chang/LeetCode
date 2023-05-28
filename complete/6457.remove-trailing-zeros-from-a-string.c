/*
 * @lc app=leetcode id=6457 lang=c
 *
 * [6457] Remove Trailing Zeros From a String
 */

// Difficulty:Easy

// Given a positive integer num represented as a string, return the integer num without trailing zeros as a string.

// Constraints:

// 1 <= num.length <= 1000
// num consists of only digits.
// num doesn't have any leading zeros.

// @lc code=start
char *removeTrailingZeros(char *num)
{
    int len = strlen(num);
    if (len == 1)
        return num;
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] != '0')
            break;
        else
            num[i] = '\0';
    }
    return num;
}
// @lc code=end