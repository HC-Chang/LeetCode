/*
 * @lc app=leetcode id=3227 lang=cpp
 *
 * [3227] Vowels Game in a String
 */

// @lc code=start
class Solution
{
public:
    bool is_vowel(char c)
    {
        switch (c)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
            break;
        }
        return false;
    }
    bool doesAliceWin(string s)
    {
        int cnt_vowel = 0;
        for (auto &c : s)
        {
            if (is_vowel(c))
                cnt_vowel++;
        }

        if (cnt_vowel == 0)
            return false;

        if (cnt_vowel % 2 == 1)
            return true;

        return cnt_vowel;
    }
};
// @lc code=end

// Note: math