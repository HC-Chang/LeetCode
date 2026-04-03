/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k)
        {
            if (i + k < n)
                reverse(s.begin() + i, s.begin() + i + k);
            else
                reverse(s.begin() + i, s.end());
        }

        return s;
    }
};
// @lc code=end

// Note: two pointers