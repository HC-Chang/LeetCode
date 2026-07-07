/*
 * @lc app=leetcode id=3754 lang=c
 *
 * [3754] Concatenate Non-Zero Digits and Multiply by Sum I
 */

// @lc code=start
long long sumAndMultiply(int n)
{
    long long ans = 0;
    long long sum = 0;
    long long idx = 1;
    while (n)
    {
        long long tmp = n % 10;
        if (tmp)
        {
            sum += tmp;
            ans += tmp * idx;
            idx *= 10;
        }
        n /= 10;
    }

    return ans * sum;
}
// @lc code=end

// Note: math