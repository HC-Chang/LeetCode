/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
class Solution
{
public:
    vector<string> split(string &str, const char &delimiter)
    {
        vector<string> result;
        stringstream ss(str);
        string tok;

        while (getline(ss, tok, delimiter))
        {
            result.push_back(tok);
        }
        return result;
    }

    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> arr1 = split(s1, ' ');
        vector<string> arr2 = split(s2, ' ');
        unordered_map<string, int> hash;
        for (auto a : arr1)
            ++hash[a];
        for (auto a : arr2)
            ++hash[a];

        vector<string> ans;
        for (auto h : hash)
        {
            if (h.second == 1)
                ans.push_back(h.first);
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table + counting