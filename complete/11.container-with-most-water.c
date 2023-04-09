/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 */

// @lc code=start
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int maxArea(int *height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;
    int area;
    while (left <= right)
    {
        area = min(height[right], height[left]) * (right - left);
        max_area = max(max_area, area);
        if (height[right] > height[left])
            left++;
        else
            right--;
    }
    return max_area;
}
// @lc code=end
