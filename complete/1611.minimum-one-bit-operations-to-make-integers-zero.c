/*
 * @lc app=leetcode id=1611 lang=c
 *
 * [1611] Minimum One Bit Operations to Make Integers Zero
 */

// @lc code=start
int minimumOneBitOperations(int n)
{
    if (n <= 1)
        return n;
    int count = 0;
    while ((1 << count) <= n)
        count++;
    return ((1 << count) - 1) - minimumOneBitOperations(n - (1 << (count - 1)));
}
// @lc code=end
