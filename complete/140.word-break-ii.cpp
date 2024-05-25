/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, vector<string>> _mem;
    vector<string> append(const vector<string> &prefixes, const string &word)
    {
        vector<string> results;
        for (const auto &prefix : prefixes)
            results.push_back(prefix + " " + word);
        return results;
    }

    const vector<string> &wordBreak(string s, unordered_set<string> &dict)
    {
        if (_mem.count(s))
            return _mem[s];

        vector<string> ans;

        if (dict.count(s))
            ans.push_back(s);

        for (int j = 1; j < s.length(); ++j)
        {
            const string &right = s.substr(j);
            if (!dict.count(right))
                continue;

            const string &left = s.substr(0, j);
            const vector<string> left_ans =
                append(wordBreak(left, dict), right);

            ans.insert(ans.end(), left_ans.begin(), left_ans.end());
        }

        _mem[s].swap(ans);
        return _mem[s];
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s, dict);
    }
};

// @lc code=end

// Note: backtracking + hash table