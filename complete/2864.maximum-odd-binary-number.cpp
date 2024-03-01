/*
 * @lc app=leetcode id=2864 lang=cpp
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
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int s_len = s.size();
        int one_count = 0;
        for (int i = 0; i < s_len; i++)
        {
            if (s[i] == '1')
                one_count++;
        }
        s.clear();
        int i;
        for (i = 0; i < one_count - 1; i++)
            s.append("1");
        for (i; i < s_len - 1; i++)
            s.append("0");
        s.append("1");
        return s;
    }
};
// @lc code=end
