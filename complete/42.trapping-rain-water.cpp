/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int pre_max = 0, post_max = 0;
        int r = 0;
        while (left <= right)
        {
            if (pre_max < height[left])
                pre_max = height[left];
            if (post_max < height[right])
                post_max = height[right];
            if (pre_max < post_max)
                r += pre_max - height[left++];
            else
                r += post_max - height[right--];
        }

        return r;
    }
};
// @lc code=end
