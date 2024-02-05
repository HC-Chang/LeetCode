/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int cnt[26] = {0};
        int n = s.size();
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            ++cnt[s[i] - 'a'];
            while (r < n && cnt[s[r] - 'a'] > 1)
                r++;
            if (r == n)
                return -1;
        }

        return r;
    }
};
// @lc code=end

// Note: hash tabel + counting