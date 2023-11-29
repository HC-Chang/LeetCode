/*
 * @lc app=leetcode id=191 lang=c
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
// Solution 2:
int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        n &= n-1;
        count++;
    }
    return count;
}
// @lc code=end

// Note: bit manipulation

// Solution 1:
// int hammingWeight(uint32_t n)
// {
//     int count = 0;
//     while (n)
//     {
//         count += n & 1;
//         n >>= 1;
//     }
//     return count;
// }