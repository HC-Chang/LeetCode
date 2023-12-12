/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int index = nums[0] > nums[1] ? 1 : 0;
        int n = nums.size();
        for (int i = 2; i < n; i++)
        {
            if (nums[i] > nums[index])
            {
                nums[index] = nums[i];
                index = nums[0] > nums[1] ? 1 : 0;
            }
        }
        return (nums[0] - 1) * (nums[1] - 1);
    }
};
// @lc code=end
