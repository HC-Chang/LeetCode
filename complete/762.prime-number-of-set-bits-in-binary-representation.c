/*
 * @lc app=leetcode id=762 lang=c
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
int countPrimeSetBits(int left, int right)
{
    int cnt = 0;
    for (int i = left; i <= right; i++)
    {
        switch (__builtin_popcount(i))
        {
        case 2:
        case 3:
        case 5:
        case 7:
        case 11:
        case 13:
        case 17:
        case 19:
            cnt++;
            break;
        }
    }
    return cnt;
}
// @lc code=end

// Note: math + bit manipulation