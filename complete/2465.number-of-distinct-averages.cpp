/*
 * @lc app=leetcode id=2465 lang=cpp
 *
 * [2465] Number of Distinct Averages
 */

// @lc code=start
class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 2)
            return 1;
        sort(nums.begin(), nums.end());
        unordered_map<int, bool> hash;
        for (int i = 0; i < n / 2; i++)
            hash.insert({nums[i] + nums[n - 1 - i], true});
        return hash.size();
    }
};
// @lc code=end

// Note: sorting + hash table