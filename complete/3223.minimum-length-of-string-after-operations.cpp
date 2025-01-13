/*
 * @lc app=leetcode id=3223 lang=cpp
 *
 * [3223] Minimum Length of String After Operations
 */

// @lc code=start
class Solution
{
public:
    int minimumLength(string s)
    {
        unordered_map<char, int> hash;
        for (auto c : s)
            ++hash[c];

        int cnt = 0;
        for (auto h : hash)
        {
            if (h.second == 0)
                continue;
            if (h.second % 2 == 0)
                cnt += 2;
            else
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end

// Note: hash table + counting