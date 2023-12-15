/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */

// @lc code=start
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<std::string, int> hash;
        int n = paths.size();
        for (int i = 0; i < n; i++)
            ++hash[paths[i][1]];
        for (int i = 0; i < n; i++)
            hash.erase(paths[i][0]);
        return hash.begin()->first;
    }
};
// @lc code=end

// Note: hash table