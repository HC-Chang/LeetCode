/*
 * @lc app=leetcode id=2958 lang=cpp
 *
 * [2958] Length of Longest Subarray With at Most K Frequency
 */

// @lc code=start
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        int max_cnt = 0;
        int n = nums.size();
        for (int i = 0, j = 0; i < n; ++i)
        {
            ++hash[nums[i]];
            while (hash[nums[i]] > k)
                --hash[nums[j++]];
            max_cnt = max(max_cnt, i - j + 1);
        }
        return max_cnt;
    }
};
// @lc code=end

// Note: hash table + sliding window