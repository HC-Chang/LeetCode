/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 */

// @lc code=start
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
            vec.emplace_back(i, heights[i]);
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b)
             { return b.second < a.second; });

        vector<string> ans;
        for (auto v : vec)
            ans.push_back(names[v.first]);

        return ans;
    }
};
// @lc code=end

// Note: hash table + sorting