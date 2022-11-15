/*
 * @lc app=leetcode id=70 lang=c
 *
 * [70] Climbing Stairs
 */

// @lc code=start
int climbStairs(int n)
{
    if (n <= 1)
        return 1;

    int last = 1;
    int current = 2;
    int temp;
    for (int i = 3; i <= n; i++)
    {
        temp = current;
        current = current + last;
        last = temp;
    }
    return current;
}
// @lc code=end
