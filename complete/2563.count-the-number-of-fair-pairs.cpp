/*
 * @lc app=leetcode id=2563 lang=cpp
 *
 * [2563] Count the Number of Fair Pairs
 */

// @lc code=start
class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        return lower_bound(upper + 1, nums) - lower_bound(lower, nums);
    }

private:
    long long lower_bound(int val, vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        long long result = 0;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum < val)
            {
                result += (right - left);
                left++;
            }
            else
                right--;
        }
        return result;
    }
};
// @lc code=end

// Note: two pointers + binary search + sorting

// Official Solution