/*
 * @lc app=leetcode id=3160 lang=cpp
 *
 * [3160] Find the Number of Distinct Colors Among the Balls
 */

// @lc code=start
class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> hash;
        unordered_map<int, int> color_hash;
        vector<int> ans;
        for (auto q : queries)
        {
            if (hash.find(q[0]) != hash.end())
            {
                if (--color_hash[hash[q[0]]] == 0)
                    color_hash.erase(hash[q[0]]);
            }
            hash[q[0]] = q[1];
            ++color_hash[hash[q[0]]];
            ans.push_back(color_hash.size());
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table