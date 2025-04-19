/*
 * @lc app=leetcode id=1337 lang=c
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int idx;
    int count;
} DATA;

int sort(const void *a, const void *b)
{
    if ((*(DATA *)a).count == (*(DATA *)b).count)
        return (*(DATA *)a).idx - (*(DATA *)b).idx;
    return (*(DATA *)a).count - (*(DATA *)b).count;
}

int *kWeakestRows(int **mat, int matSize, int *matColSize, int k, int *returnSize)
{
    DATA data[matSize];
    for (int i = 0; i < matSize; i++)
    {
        data[i].idx = i;
        data[i].count = 0;
        for (int j = 0; j < matColSize[i]; j++)
        {
            if (mat[i][j] == 1)
                ++data[i].count;
        }
    }
    qsort(&data, matSize, sizeof(DATA), sort);

    *returnSize = 0;
    int *r = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
        r[(*returnSize)++] = data[i].idx;

    return r;
}

// @lc code=end
