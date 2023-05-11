/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start
int mySqrt(int x)
{
    if (x <= 1)
        return x;
    else if (x < 4)
        return 1;
    int left = 0;
    int right = 65536;
    int middle;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (middle == x / middle)
            return middle;
        else if (middle > x / middle)
            right = middle - 1;
        else if (middle < x / middle)
            left = middle + 1;
    }
    if (left > x / left)
        return left - 1;
    return left;
}
// @lc code=end
