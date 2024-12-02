/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int cnt = 1;
        stringstream ss(sentence);
        string t;
        char del = ' ';
        while (getline(ss, t, del))
        {
            if (t.find(searchWord) == 0)
                return cnt;
            else
                cnt++;
        }
        return -1;
    }
};
// @lc code=end

// Note: two pointers