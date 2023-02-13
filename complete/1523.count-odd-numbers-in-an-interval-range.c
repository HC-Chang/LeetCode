/*
 * @lc app=leetcode id=1523 lang=c
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start

int countOdds(int low, int high)
{
    if (!(low & 1))
        low++;

    return low > high ? 0 : (high - low) / 2 + 1;
}
// @lc code=end
