/*
 * @lc app=leetcode id=3011 lang=cpp
 *
 * [3011] Find if Array Can Be Sorted
 */

// @lc code=start
class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] <= nums[i + 1])
                continue;
            else
            {
                if (__builtin_popcount(nums[i]) ==
                    __builtin_popcount(nums[i + 1]))
                    swap(nums[i], nums[i + 1]);
                else
                    return false;
            }
        }

        for (int i = n - 1; i >= 1; i--)
        {
            if (nums[i] >= nums[i - 1])
                continue;
            else
            {
                if (__builtin_popcount(nums[i]) ==
                    __builtin_popcount(nums[i - 1]))
                    swap(nums[i], nums[i - 1]);
                else
                    return false;
            }
        }

        return true;
    }
};
// @lc code=end

// Note: bit manipulation

// Official Solution