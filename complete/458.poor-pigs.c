/*
 * @lc app=leetcode id=458 lang=c
 *
 * [458] Poor Pigs
 */

// @lc code=start
#include <fenv.h>
int poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
    fesetround(FE_UPWARD);
    return rint(log(buckets) / log(minutesToTest / minutesToDie + 1));
}
// @lc code=end