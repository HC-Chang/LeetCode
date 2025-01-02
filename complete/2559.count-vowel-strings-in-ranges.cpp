/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start
class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words,
                             vector<vector<int>> &queries)
    {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        vector<int> prefix_sum(words.size());
        int sum = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string currentWord = words[i];
            if (vowels.count(currentWord[0]) && vowels.count(currentWord[currentWord.size() - 1]))
                sum++;

            prefix_sum[i] = sum;
        }

        vector<int> ans;
        for (auto q: queries)
            ans.push_back(prefix_sum[q[1]] - (q[0] == 0 ? 0 : prefix_sum[q[0] - 1]))

        return ans;
    }
};
// @lc code=end

// Note: prefix sum

// Official Solution