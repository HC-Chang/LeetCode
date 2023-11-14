/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.size();
        int count = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            int l = 0, r = n - 1;

            while (l < n && s[l] != ch)
                ++l;

            while (r >= 0 && s[r] != ch)
                --r;

            if (r - l < 2)
                continue;

            unordered_set<char> charset;
            for (int k = l + 1; k < r; ++k)
            {
                charset.insert(s[k]);
            }
            count += charset.size();
        }
        return count;
    }
};
// @lc code=end

// Official Solution

// Note: hash table