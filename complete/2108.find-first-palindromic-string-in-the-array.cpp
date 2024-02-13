/*
 * @lc app=leetcode id=2108 lang=cpp
 *
 * [2108] Find First Palindromic String in the Array
 */

// @lc code=start
class Solution
{
public:
    bool is_palindromic(string w)
    {
        int l = 0;
        int r = w.size() - 1;
        while (l < r)
        {
            if (w[l++] != w[r--])
                return false;
        }
        return true;
    }

    string firstPalindrome(vector<string> &words)
    {
        for (auto w : words)
        {
            if (is_palindromic(w))
                return w;
        }
        return "";
    }
};
// @lc code=end

// Note: two pointers