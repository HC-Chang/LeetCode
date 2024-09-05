/*
 * @lc app=leetcode id=2028 lang=c
 *
 * [2028] Find Missing Observations
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *missingRolls(int *rolls, int rollsSize, int mean, int n, int *returnSize)
{
    int sum = 0;
    for (int i = 0; i < rollsSize; i++)
        sum += rolls[i];

    int diff = mean * (rollsSize + n) - sum;
    int q = diff / n;
    int r = diff % n;
    if (((sum + n * 6) / (rollsSize + n) < mean) ||
        ((sum + n) / (rollsSize + n) > mean) || q == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = n;
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (r-- > 0)
            arr[i] = q + 1;
        else
            arr[i] = q;
    }

    return arr;
}
// @lc code=end

// Note: math