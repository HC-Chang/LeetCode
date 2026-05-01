/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        int sum = nums[0];
        int tmp = 0;
        for (int i = 1; i < n; i++)
        {
            tmp += nums[i] * i;
            sum += nums[i];
        }
        int ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            tmp += sum - n * nums[i];
            ans = max(ans, tmp);
        }

        return ans;
    }
};
// @lc code=end

// Note: math + DP