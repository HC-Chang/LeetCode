/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> ans;
        unordered_map<char, int> hash;
        unordered_map<char, int> t_hash;
        for (auto w : words2)
        {
            t_hash.clear();
            for (auto ww : w)
                ++t_hash[ww];
            for (auto h : t_hash)
                hash[h.first] = max(hash[h.first], t_hash[h.first]);
        }

        bool flag;
        for (auto w : words1)
        {
            flag = true;
            t_hash.clear();

            for (auto ww : w)
                ++t_hash[ww];

            for (auto h : hash)
            {
                if (t_hash.find(h.first) == t_hash.end() ||
                    t_hash[h.first] < hash[h.first])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(w);
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table