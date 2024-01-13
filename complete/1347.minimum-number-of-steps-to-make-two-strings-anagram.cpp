/*
 * @lc app=leetcode id=1347 lang=cpp
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
 */

// @lc code=start
class Solution
{
public:
    int minSteps(string s, string t)
    {
        int hash[26] = {0};
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            ++hash[s[i] - 'a'];
            --hash[t[i] - 'a'];
        }
        int cnt = 0;
        for (auto i : hash)
            cnt += abs(i);
        return cnt / 2;
    }
};
// @lc code=end

// Note: hash table