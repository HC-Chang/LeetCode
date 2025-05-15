/*
 * @lc app=leetcode id=2900 lang=cpp
 *
 * [2900] Longest Unequal Adjacent Groups Subsequence I
 */

// @lc code=start
class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || groups[i] != groups[i - 1])
                ans.emplace_back(words[i]);
        }
        return ans;
    }
};
// @lc code=end

// Note: DP + greedy