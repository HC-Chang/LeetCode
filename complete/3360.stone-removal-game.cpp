/*
 * @lc app=leetcode id=3360 lang=cpp
 *
 * [3360] Stone Removal Game
 */

// @lc code=start
class Solution
{
public:
    bool canAliceWin(int n)
    {
        char cnt = 0;
        int tmp = 10;
        while (n >= 0)
        {
            n -= tmp;
            --tmp;
            cnt++;
        }

        return cnt % 2 == 0;
    }
};
// @lc code=end

// Note: math