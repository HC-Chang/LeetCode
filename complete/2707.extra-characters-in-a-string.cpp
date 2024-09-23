/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
class Solution
{
public:
    unsigned long hash(string &str)
    {
        unsigned long hash = 5381;
        int count = str.size();
        for (int i = 0; i < count; i++)
            hash = ((hash << 5) + hash) + str[i];

        return hash;
    }

    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.size();
        int nn = dictionary.size();

        vector<unsigned long> hashs(nn);
        for (int i = 0; i < nn; i++)
            hashs[i] = hash(dictionary[i]);

        vector<int> dp(n + 1);
        string ss;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < i; ++j)
            {
                for (int k = 0; k < nn; k++)
                {
                    ss = s.substr(j, i - j);
                    if (hash(ss) == hashs[k])
                        dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

// Note: hash . DP . Trie