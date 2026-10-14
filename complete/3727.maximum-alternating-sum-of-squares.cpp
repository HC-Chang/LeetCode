/*
 * @lc app=leetcode id=3727 lang=cpp
 *
 * [3727] Maximum Alternating Sum of Squares
 */

// @lc code=start
class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
                nums[i] *= -1;
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (int i = 0; i < n / 2; i++)
            sum -= nums[i] * nums[i];
        for (int i = n / 2; i < n; i++)
            sum += nums[i] * nums[i];
        return sum;
    }
};
// @lc code=end

// Note: sorting