/*
 * @lc app=leetcode id=1750 lang=cpp
 *
 * [1750] Minimum Length of String After Deleting Similar Ends
 */

// @lc code=start
class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.size();
        int l = 0;
        int r = n - 1;
        char c;
        while (l < r)
        {
            c = s[l];
            if (s[l++] == s[r--])
            {
                while (c == s[l] && l <= r)
                    l++;
                while (c == s[r] && l <= r)
                    r--;
                n = r - l + 1;
            }
            else
                break;
        }
        if (n < 0)
            return 0;
        return n;
    }
};
// @lc code=end

// Note: two pointers