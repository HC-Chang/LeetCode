/*
 * @lc app=leetcode id=1967 lang=cpp
 *
 * [1967] Number of Strings That Appear as Substrings in Word
 */

// @lc code=start
class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int cnt = 0;
        for (auto &p : patterns)
        {
            if (word.find(p) != string::npos)
                cnt++;
        }

        return cnt;
    }
};
// @lc code=end
