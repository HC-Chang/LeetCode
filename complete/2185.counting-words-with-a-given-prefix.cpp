/*
 * @lc app=leetcode id=2185 lang=cpp
 *
 * [2185] Counting Words With a Given Prefix
 */

// @lc code=start
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int cnt = 0;
        int n = pref.size();
        for (auto w : words)
        {
            if (w.find(pref) == 0)
                ++cnt;
        }
        return cnt;
    }
};
// @lc code=end
