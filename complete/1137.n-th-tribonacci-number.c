/*
 * @lc app=leetcode id=1137 lang=c
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start

int tribonacci(int n)
{
    int F[38] = {0};
    F[1] = 1;
    F[2] = 1;
    if (n < 3)
        return F[n];
    for (int i = 3; i < n + 1; i++)
        F[i] = F[i - 1] + F[i - 2] + F[i - 3];
    return F[n];
}
// @lc code=end

// Note: DP