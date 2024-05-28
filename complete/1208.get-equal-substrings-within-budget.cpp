/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
 */

// @lc code=start
class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();
        int cur = 0;
        int start = 0;
        int max_len = 0;
        for (int i = 0; i < n; ++i)
        {
            cur += abs(s[i] - t[i]);
            while (cur > maxCost && start <= i)
            {
                cur -= abs(s[start] - t[start]);
                ++start;
            }
            max_len = max(max_len, i - start + 1);
        }
        return max_len;
    }
};
// @lc code=end

// Note: sliding window + prefix sum