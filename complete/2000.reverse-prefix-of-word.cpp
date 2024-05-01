/*
 * @lc app=leetcode id=2000 lang=cpp
 *
 * [2000] Reverse Prefix of Word
 */

// @lc code=start
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int n = word.size();
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (word[i] == ch)
            {
                idx = i;
                break;
            }
        }
        char tmp;
        for (int i = 0; i < idx / 2 + 1; i++)
        {
            tmp = word[idx - i];
            word[idx - i] = word[i];
            word[i] = tmp;
        }
        return word;
    }
};
// @lc code=end

// Note: two pointers