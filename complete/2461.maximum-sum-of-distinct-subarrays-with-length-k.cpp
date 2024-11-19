/*
 * @lc app=leetcode id=2461 lang=cpp
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
 */

// @lc code=start
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long mas_sum = 0;
        long long tmp_sum = 0;
        int l = 0;
        int r = 0;

        unordered_map<int, int> hash;

        while (r < nums.size())
        {
            int currNum = nums[r];
            int lastOccurrence = (hash.count(currNum) ? hash[currNum] : -1);

            while (l <= lastOccurrence || r - l + 1 > k)
            {
                tmp_sum -= nums[l];
                l++;
            }
            hash[currNum] = r;
            tmp_sum += nums[r];
            if (r - l + 1 == k)
                mas_sum = max(mas_sum, tmp_sum);

            r++;
        }
        return mas_sum;
    }
};
// @lc code=end

// Note: hash table + sliding window

// Official Solution