/*
 * @lc app=leetcode id=2553 lang=cpp
 *
 * [2553] Separate the Digits in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--)
        {
            while (nums[i] > 0)
            {
                ans.push_back(nums[i] % 10);
                nums[i] /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
