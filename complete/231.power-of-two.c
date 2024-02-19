/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */

// @lc code=start
// Solution 2: bit manipulation
bool isPowerOfTwo(int n)
{
    long int x = n;
    if (n && !(n & (x - 1)))
        return true;
    return false;
}
// @lc code=end

// Note: bit manipulation

// Solution 1: recursion
// bool isPowerOfTwo(int n)
// {
//     if (n == 1)
//         return true;
//     else if (n <= 0)
//         return false;
//     if (n % 2 != 0)
//         return false;
//     return isPowerOfTwo(n / 2);
// }