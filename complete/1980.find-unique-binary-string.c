/*
 * @lc app=leetcode id=1980 lang=c
 *
 * [1980] Find Unique Binary String
 */

// @lc code=start
char *findDifferentBinaryString(char **nums, int numsSize)
{
    int n = numsSize;
    char *r = malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++)
        r[i] = '0';
    for (int i = 0; i < n; ++i)
        r[i] = '1' - nums[i][i] + '0';
    r[n] = 0;
    return r;
}
// @lc code=end
