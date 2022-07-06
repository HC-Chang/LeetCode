/*
 * @lc app=leetcode id=509 lang=c
 *
 * [509] Fibonacci Number
 */

// @lc code=start

int fib(int n)
{
    if (n < 2)
        return n;

    return fib(n - 1) + fib(n - 2);
}
// @lc code=end
