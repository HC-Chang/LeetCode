/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        for (auto n : nums)
            ++hash[n];
        vector<pair<int, int>> elems(hash.begin(), hash.end());
        sort(elems.begin(), elems.end(), [](pair<int, int> a, pair<int, int> b)
             {
            if(a.second == b.second)
                return a.first > b.first;
            return a.second < b.second; });

        vector<int> ans;
        for (auto e : elems)
        {
            for (int i = 0; i < e.second; i++)
                ans.push_back(e.first);
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table + sorting