/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
class Solution
{
public:
    int bin_search_left(vector<int> &arr, int target)
    {
        int left = 0;
        int right = arr.size();
        int middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (target > arr[middle])
                left = middle + 1;
            else
                right = middle;
        }
        return left;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ret(2, -1);
        int l = bin_search_left(nums, target);
        if (l == n || nums[l] != target)
            return ret;
        int r = bin_search_left(nums, target + 1) - 1;
        ret[0] = l;
        ret[1] = r;
        return ret;
    }
};
// @lc code=end

// Note: binary search