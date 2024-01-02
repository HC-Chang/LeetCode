/*
 * @lc app=leetcode id=2610 lang=cpp
 *
 * [2610] Convert an Array Into a 2D Array With Conditions
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        int max = 0;
        for (auto i : nums)
        {
            ++hash[i];
            if (hash[i] > max)
                max = hash[i];
        }
        vector<vector<int>> ans = vector<vector<int>>(max);
        for (auto h : hash)
        {
            for (int i = 0; i < h.second; i++)
                ans[i].push_back(h.first);
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table