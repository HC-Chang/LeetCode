/*
 * @lc app=leetcode id=2901 lang=cpp
 *
 * [2901] Longest Unequal Adjacent Groups Subsequence II
 */

// @lc code=start
class Solution
{
public:
    bool is_hamming_distance_eq1(string a, string b)
    {
        int n1 = a.size();
        int n2 = b.size();
        if (n1 != n2)
            return false;
        int cnt = 0;
        for (int i = 0; i < n1; i++)
        {
            if (a[i] != b[i])
                cnt++;
            if (cnt >= 2)
                return false;
        }
        return true;
    }

    vector<string> getWordsInLongestSubsequence(vector<string> &words,
                                                vector<int> &groups)
    {
        int n = groups.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxIndex = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (is_hamming_distance_eq1(words[i], words[j]) == 1 && dp[j] + 1 > dp[i] &&
                    groups[i] != groups[j])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex])
                maxIndex = i;
        }

        vector<string> ans;
        for (int i = maxIndex; i >= 0; i = prev[i])
            ans.emplace_back(words[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

// Note: DP