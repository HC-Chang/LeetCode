/*
 * @lc app=leetcode id=1009 lang=c
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
int bitwiseComplement(int n)
{
    if (n == 0)
        return 1;
    int ans = 0;
    int i = 0;
    int tmp;
    while (n > 0)
    {
        tmp = 1 << i;
        ans += n & tmp > 0 ? 0 : tmp;
        i++;
        n >>= 1;
    }
    return ans;
}
// @lc code=end

// Note: bit manipulation