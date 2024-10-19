/*
 * @lc app=leetcode id=1545 lang=c
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start
char findKthBit(int n, int k)
{
    int in_section = k & -k;
    bool is_inverse = ((k / in_section) >> 1 & 1) == 1;
    bool is_one = (k & 1) == 0;

    if (is_inverse)
        return is_one ? '0' : '1';
    else
        return is_one ? '1' : '0';
}
// @lc code=end

// Note: bit manipulation

// Official Solution