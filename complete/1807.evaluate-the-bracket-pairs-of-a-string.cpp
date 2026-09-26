/*
 * @lc app=leetcode id=1807 lang=cpp
 *
 * [1807] Evaluate the Bracket Pairs of a String
 */

// @lc code=start
class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        unordered_map<string, string> hash;
        for (auto const k : knowledge)
            hash[k[0]] = k[1];

        int l = 0;
        int r = 0;
        while ((l = s.find("(", l)) != -1)
        {
            r = s.find(")", l);
            if (r == -1)
                break;

            string tmp = s.substr(l + 1, r - l - 1);
            s.replace(l, r - l + 1, hash.find(tmp) == hash.end() ? "?" : hash[tmp]);
        }
        return s;
    }
};
// @lc code=end

// Note: hash table