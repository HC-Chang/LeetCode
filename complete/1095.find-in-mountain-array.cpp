/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length(), l, r, m, peak = 0;
        l = 0;
        r = n - 1;
        while (l < r)
        {
            m = (l + r) / 2;
            if (mountainArr.get(m) < mountainArr.get(m + 1))
                l = peak = m + 1;
            else
                r = m;
        }
        l = 0;
        r = peak;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (mountainArr.get(m) < target)
                l = m + 1;
            else if (mountainArr.get(m) > target)
                r = m - 1;
            else
                return m;
        }
        l = peak;
        r = n - 1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (mountainArr.get(m) > target)
                l = m + 1;
            else if (mountainArr.get(m) < target)
                r = m - 1;
            else
                return m;
        }
        return -1;
    }
};
// @lc code=end

// Note: binary search