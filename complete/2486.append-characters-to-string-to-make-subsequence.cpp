/*
 * @lc app=leetcode id=2486 lang=cpp
 *
 * [2486] Append Characters to String to Make Subsequence
 */

// @lc code=start
class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int len_t = t.size();
        int idx = 0;
        for (auto c : s)
        {
            if (c == t[idx])
                idx++;
        }
        return len_t - idx;
    }
};
// @lc code=end

// Note: two pointers
