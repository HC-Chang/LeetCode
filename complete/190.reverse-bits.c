/*
 * @lc app=leetcode id=190 lang=c
 *
 * [190] Reverse Bits
 */

// @lc code=start
uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
        ans += (((n & ((uint32_t)1 << i)) > 0) * ((uint32_t)1 << ((uint32_t)31 - i)));

    return ans;
}
// @lc code=end

// Note: bit manipulation