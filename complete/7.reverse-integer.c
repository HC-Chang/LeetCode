/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

// @lc code=start

int reverse(int x)
{
    int y = 0;
    while (x != 0)
    {
        // NOTE overflow judge
        if (y > INT_MAX / 10 || y < INT_MIN / 10)
            return 0;
        else if (y == INT_MAX / 10 || y == INT_MIN / 10)
        {
            if (x % 10 > 7 || x % 10 < -8)
                return 0;
        }
        
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

// @lc code=end
