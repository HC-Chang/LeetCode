/*
 * @lc app=leetcode id=1652 lang=c
 *
 * [1652] Defuse the Bomb
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *decrypt(int *code, int codeSize, int k, int *returnSize)
{
    int n = codeSize;
    *returnSize = n;
    if (k == 0)
    {
        memset(code, 0, n * sizeof(int));
        return code;
    }

    int tmp[n];
    memcpy(&tmp, code, sizeof(tmp));

    int flag = k > 0 ? 1 : 0;
    k = abs(k);
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            tmp[j] += code[(j + i) % n];
    }

    for (int i = 0; i < n; i++)
    {
        if (flag)
            code[i] = tmp[(i + 1) % n];
        else
            code[i] = tmp[(i - k + n) % n];
    }

    return code;
}
// @lc code=end

// Note: sliding window