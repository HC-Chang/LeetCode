/*
 * @lc app=leetcode id=2864 lang=c
 *
 * [2864] Maximum Odd Binary Number
 */

// Difficulty:Easy
// You are given a binary string s that contains at least one '1'.

// You have to rearrange the bits in such a way
// that the resulting binary number is the maximum odd binary number
// that can be created from this combination.
// Return a string representing the maximum odd binary number
// that can be created from the given combination.

// Note that the resulting string can have leading zeros.

// Constraints:
// 1 <= s.length <= 100
// s consists only of '0' and '1'.
// s contains at least one '1'.

// @lc code=start
char *maximumOddBinaryNumber(char *s)
{
    int s_len = strlen(s);
    int one_count = 0;
    for (int i = 0; i < s_len; i++)
    {
        if (s[i] == '1')
            one_count++;
    }
    memset(s, '0', s_len * sizeof(char));
    for (int i = 0; i < one_count - 1; i++)
        s[i] = '1';
    s[s_len - 1] = '1';
    return s;
}
// @lc code=end
