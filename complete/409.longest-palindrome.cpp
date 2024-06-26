/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int map[60] = {0};

        for (auto c : s)
            ++map[c - 'A'];

        int r = 0;
        int temp_len;
        for (int i = 0; i < 60; ++i)
        {
            temp_len = map[i];
            if (map[i] % 2 == 1)
                temp_len--;

            r += temp_len;
            if (r % 2 == 0 && map[i] % 2 == 1)
                r++;
        }

        return r;
    }
};
// @lc code=end
