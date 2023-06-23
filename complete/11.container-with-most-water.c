/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 */

// @lc code=start
int maxArea(int *height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;
    int area;
    while (left < right)
    {
        area = fmin(height[right], height[left]) * (right - left);
        max_area = fmax(max_area, area);
        if (height[right] > height[left])
            left++;
        else
            right--;
    }
    return max_area;
}
// @lc code=end
