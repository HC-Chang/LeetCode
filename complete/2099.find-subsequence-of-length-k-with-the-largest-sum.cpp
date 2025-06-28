/*
 * @lc app=leetcode id=2099 lang=cpp
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({i, nums[i]});

        sort(arr.begin(), arr.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.second > b.second;
             });

        while (arr.size() > k)
            arr.pop_back();

        sort(arr.begin(), arr.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.first < b.first;
             });

        vector<int> ans;
        for (auto a : arr)
            ans.push_back(a.second);
        return ans;
    }
};
// @lc code=end

// Note: heap + sorting