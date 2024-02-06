/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        for (string str : strs)
        {
            vector<int> cnt(26);
            string t;
            for (char c : str)
                ++cnt[c - 'a'];
            for (int i = 0; i < 26; ++i)
            {
                if (cnt[i] == 0)
                    continue;
                t += string(1, i + 'a') + to_string(cnt[i]);
            }
            map[t].push_back(str);
        }
        for (auto a : map)
            ans.push_back(a.second);
        return ans;
    }
};
// @lc code=end

// Note: sorting + hash table