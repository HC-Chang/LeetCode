/*
 * @lc app=leetcode id=1894 lang=c
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start
int chalkReplacer(int *chalk, int chalkSize, int k)
{
    if (chalk[0] > k)
        return 0;
    long long sum = 0;
    for (int i = 0; i < chalkSize; i++)
        sum += chalk[i];

    k %= sum;
    for (int i = 0; i < chalkSize; i++)
    {
        k -= chalk[i];
        if (k < 0)
            return i;
    }
    return chalkSize - 1;
}
// @lc code=end

// Note: prefix sum