/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> hash;
        for (auto c : s)
            ++hash[c];

        vector<pair<char, int>> vec(hash.begin(), hash.end());
        sort(vec.begin(), vec.end(), [](pair<char, int> a, pair<char, int> b)
             { return b.second < a.second; });

        s.clear();
        int cnt;
        for (auto v : vec)
        {
            cnt = v.second;
            for (int i = 0; i < cnt; i++)
                s += v.first;
        }
        return s;
    }
};
// @lc code=end

// Note: hash table + counting + sorting