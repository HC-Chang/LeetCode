/*
 * @lc app=leetcode id=3042 lang=cpp
 *
 * [3042] Count Prefix and Suffix Pairs I
 */

// @lc code=start
class Solution
{
public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int n1 = words[i].size();
                int n2 = words[j].size();
                if (n1 > n2)
                    continue;
                if (words[j].substr(0, n1) == words[i] && words[j].substr(n2 - n1, n1) == words[i])
                    cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

// Note: hash