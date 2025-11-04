/*
 * @lc app=leetcode id=3318 lang=cpp
 *
 * [3318] Find X-Sum of All K-Long Subarrays I
 */

// @lc code=start
class Solution
{
public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++)
        {
            unordered_map<int, int> hash;
            for (int j = 0; j < k; j++)
                ++hash[nums[i + j]];
            vector<pair<int, int>> freq;
            for (const auto &[key, value] : hash)
                freq.emplace_back(value, key);

            sort(freq.begin(), freq.end(), greater<pair<int, int>>());

            int sum = 0;

            for (int j = 0; j < min(x, (int)freq.size()); j++)
                sum += freq[j].first * freq[j].second;
            ans.push_back(sum);
        }

        return ans;
    }
};
// @lc code=end

// Note: sliding window + hash table
