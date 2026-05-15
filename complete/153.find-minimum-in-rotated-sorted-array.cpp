/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int n = nums.size();
        int right = n - 1;
        int mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] <= nums[n - 1])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};
// @lc code=end

// Note: binary search