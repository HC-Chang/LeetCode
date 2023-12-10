/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int max_sum = 0;
        int sum = 0;
        vector<int> hash(10001, 0);
        int l = 0;
        int r = 0;
        int n = nums.size();
        while (r < n)
        {
            if (hash[nums[r]]++ == 0)
                sum += nums[r];
            else
            {
                if (sum > max_sum)
                    max_sum = sum;
                sum += nums[r];
                while (l < r && hash[nums[l]]-- >= 1)
                {
                    sum -= nums[l];
                    if (hash[nums[l++]] == 1)
                        break;
                }
            }
            r++;
        }
        if (sum > max_sum)
            max_sum = sum;
        return max_sum;
    }
};
// @lc code=end

// Note: hash table + sliding window