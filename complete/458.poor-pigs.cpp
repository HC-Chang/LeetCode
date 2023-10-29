/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 */

// @lc code=start
class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        fesetround(FE_UPWARD);
        return rint(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};
// @lc code=end