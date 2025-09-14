/*
 * @lc app=leetcode id=966 lang=cpp
 *
 * [966] Vowel Spellchecker
 */

// @lc code=start
class Solution
{
public:
    bool is_vowel(char &c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

    string s_lower(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    string mask_vowels(string s)
    {
        string ss;
        for (auto c : s)
        {
            if (is_vowel(c))
                ss += "*";
            else
                ss += c;
        }
        return ss;
    }

    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        unordered_map<string, string> hash;
        unordered_map<string, string> lower_hash;
        unordered_map<string, string> vowel_hash;
        for (auto s : wordlist)
        {
            hash[s] = s;
            string ss = s_lower(s);
            if (lower_hash.find(ss) == lower_hash.end())
                lower_hash[ss] = s;
            ss = mask_vowels(ss);
            if (vowel_hash.find(ss) == vowel_hash.end())
                vowel_hash[ss] = s;
        }

        for (auto &q : queries)
        {
            string s = s_lower(q);
            string ss = mask_vowels(s);
            if (hash.find(q) != hash.end())
                q = hash[q];
            else if (lower_hash.find(s) != lower_hash.end())
                q = lower_hash[s];
            else if (vowel_hash.find(ss) != vowel_hash.end())
                q = vowel_hash[ss];
            else
                q = "";
        }

        return queries;
    }
};
// @lc code=end

// Note: hash table