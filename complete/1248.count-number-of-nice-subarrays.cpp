/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int res = 0;
        int cur = 0;
        int n = nums.size();
        unordered_map<int, int> hash;
        hash[0] = 1;

        for (int i = 0; i < n; ++i)
        {
            cur += nums[i] & 1;
            res += hash[cur - k];
            ++hash[cur];
        }
        return res;
    }
};
// @lc code=end

// Note: hash table + math