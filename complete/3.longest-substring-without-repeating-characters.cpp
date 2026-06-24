/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n < 1)
            return n;

        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<char, int> hash;
        while (r < n)
        {
            while (r < n && hash[s[r]] == 0)
                ++hash[s[r++]];
            ans = max(r - l, ans);
            if (r >= n)
                break;
            while (s[l] != s[r])
                --hash[s[l++]];
            --hash[s[r]];
            l++;
        }

        return ans;
    }
};
// @lc code=end

// Note: sliding window