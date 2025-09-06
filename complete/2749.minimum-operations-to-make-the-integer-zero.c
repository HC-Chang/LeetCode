/*
 * @lc app=leetcode id=2749 lang=c
 *
 * [2749] Minimum Operations to Make the Integer Zero
 */

// @lc code=start
int makeTheIntegerZero(int num1, int num2)
{
    int cnt = 1;
    while (1)
    {
        long long tmp = num1 - static_cast<long long>(num2) * cnt;
        if (tmp < cnt)
            return -1;
        if (cnt >= __builtin_popcountll(tmp))
            return cnt;
        cnt++;
    }
    return -1;
}
// @lc code=end

// Note: bit-manipulation + enumeration

// Official Solution