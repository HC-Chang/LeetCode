/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution
{
public:
    bool is_vowels(char c)
    {
        switch (c)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
            break;
        }
        return false;
    }
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (is_vowels(s[i]))
                cnt++;
            if (is_vowels(s[n - 1 - i]))
                cnt--;
        }
        return cnt == 0;
    }
};
// @lc code=end
