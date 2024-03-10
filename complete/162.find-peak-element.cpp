/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution
{
public:
    int binary_search(vector<int> &nums, int left, int right)
    {
        int mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int findPeakElement(vector<int> &nums)
    {
        return binary_search(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

// Note: binary search