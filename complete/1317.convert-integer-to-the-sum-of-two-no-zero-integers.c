/*
 * @lc app=leetcode id=1317 lang=c
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool has_zero(int val)
{
    while (val)
    {
        if (val % 10 == 0)
            return true;
        val /= 10;
    }
    return false;
}

int *getNoZeroIntegers(int n, int *returnSize)
{
    *returnSize = 2;
    int *ans = malloc(2 * sizeof(int));
    for (int i = 1; i < n; i++)
    {
        if (!has_zero(i) && !has_zero(n - i))
        {
            ans[0] = i;
            ans[1] = n - i;
            break;
        }
    }
    return ans;
}
// @lc code=end

// Note: math