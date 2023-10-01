/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        int l = 0, r = 0;
        int n = s.size();
        while (l < n && r < n)
        {
            while (r < n && s[r] != ' ')
                ++r;
            for (int i = l, j = r - 1; i < j; ++i, --j)
                swap(s[i], s[j]);

            l = ++r;
        }
        return s;
    }
};
// @lc code=end

// Note: two pointers