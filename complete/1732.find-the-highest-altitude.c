/*
 * @lc app=leetcode id=1732 lang=c
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
int largestAltitude(int *gain, int gainSize)
{
    int max = gain[0] > 0 ? gain[0] : 0;
    for (int i = 1; i < gainSize; i++)
    {
        gain[i] += gain[i - 1];
        if (gain[i] > max)
            max = gain[i];
    }
    return max;
}
// @lc code=end
