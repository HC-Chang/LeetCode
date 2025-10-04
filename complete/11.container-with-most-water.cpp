/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;
        int w, h;
        int n = height.size();
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            w = r - l;
            h = min(height[l], height[r]);
            if (w * h > max)
                max = w * h;
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return max;
    }
};
// @lc code=end

// Note: two pointers + greedy