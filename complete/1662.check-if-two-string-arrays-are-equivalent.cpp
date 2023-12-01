/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

// @lc code=start
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1 = "";
        string s2 = "";
        int i;
        for (i = 0; i < word1.size(); i++)
            s1 += word1[i];
        for (i = 0; i < word2.size(); i++)
            s2 += word2[i];
        return !s1.compare(s2);
    }
};
// @lc code=end
