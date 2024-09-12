/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int hash = 0;
        for (auto a : allowed)
            hash |= 1 << (a - 'a');

        int cnt = 0;
        int pass = 0;
        for (auto s : words)
        {
            pass = 0;
            for (auto ss : s)
            {
                if (!(hash & 1 << (ss - 'a')))
                {
                    pass = 1;
                    break;
                }
            }
            if (!pass)
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end

// Note: hash table + bit manipulation