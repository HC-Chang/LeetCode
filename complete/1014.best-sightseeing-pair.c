/*
 * @lc app=leetcode id=1014 lang=c
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
int maxScoreSightseeingPair(int *values, int valuesSize)
{
    int offset = INT_MIN;
    int b_value = INT_MIN;
    for (int i = valuesSize - 2; i >= 0; i--)
    {
        offset = fmax(values[i + 1] - i - 1, offset);
        b_value = fmax(values[i] + i + offset, b_value);
    }
    return b_value;
}
// @lc code=end

// Note: DP