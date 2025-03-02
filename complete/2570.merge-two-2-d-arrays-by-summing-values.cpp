/*
 * @lc app=leetcode id=2570 lang=cpp
 *
 * [2570] Merge Two 2D Arrays by Summing Values
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        unordered_map<int, int> hash;
        for (auto n : nums1)
            hash[n[0]] += n[1];
        for (auto n : nums2)
            hash[n[0]] += n[1];

        vector<vector<int>> ans;
        for (auto h : hash)
            ans.push_back({h.first, h.second});
        sort(ans.begin(), ans.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        return ans;
    }
};
// @lc code=end

// Note: hash table + two pointers