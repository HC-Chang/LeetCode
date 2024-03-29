/*
 * @lc app=leetcode id=2962 lang=cpp
 *
 * [2962] Count Subarrays Where Max Element Appears at Least K Times
 */

// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int max_val = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        int cnt = 0, j = 0;
        for (auto i : nums)
        {
            while (j < n && cnt < k)
                cnt += nums[j++] == max_val;
            if (cnt < k)
                break;

            ans += n - j + 1;
            cnt -= i == max_val;
        }
        return ans;
    }
};
// @lc code=end

// Note: sliding window