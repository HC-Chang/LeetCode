/*
 * @lc app=leetcode id=3516 lang=cpp
 *
 * [3516] Find Closest Person
 */

// @lc code=start
class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        if (abs(z - x) == abs(z - y))
            return 0;
        return abs(z - x) > abs(z - y) ? 2 : 1;
    }
};
// @lc code=end

// Note: math
