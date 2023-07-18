/*
 * @lc app=leetcode id=338 lang=c
 *
 * [338] Counting Bits
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Solution 2: 
int *countBits(int n, int *returnSize)
{
    int *r = calloc(n + 1, sizeof(int));
    *returnSize = n + 1;

    int num;
    for (int i = 0; i <= n; i++)
    {
        num = i;
        while (num)
        {
            r[i]++;
            num &= (num - 1);
        }
    }

    return r;
}
// @lc code=end

// Solution 1:

// int *countBits(int n, int *returnSize)
// {
//     int *r = malloc((n + 1) * sizeof(int));
//     *returnSize = 0;
//     if (n == 0)
//     {
//         r[(*returnSize)++] = 0;
//         return r;
//     }
//     else
//     {
//         for (int i = 0; i < 2; i++)
//             r[(*returnSize)++] = i;
//     }
//     for (int i = 2; i < n + 1; i++)
//         r[(*returnSize)++] = r[i / 2] + r[i % 2];

//     return r;
// }
