/*
 * @lc app=leetcode id=6296 lang=c
 *
 * [6297] Sort the Students by Their Kth Score
 */

// Difficulty:Medium

// There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.
// You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.
// Return the matrix after sorting it.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// @lc code=start

typedef struct
{
    int index;
    int val;
} DATA;

int sort(const void *a, const void *b)
{
    DATA *a1 = (DATA *)a;
    DATA *b1 = (DATA *)b;
    return b1->val - a1->val;
}

int **sortTheStudents(int **score, int scoreSize, int *scoreColSize, int k, int *returnSize, int **returnColumnSizes)
{
    *returnSize = scoreSize;
    *returnColumnSizes = scoreColSize;

    DATA *data = malloc(scoreSize * sizeof(DATA));
    for (int i = 0; i < scoreSize; i++)
    {
        data[i].index = i;
        data[i].val = score[i][k];
    }

    int **r = calloc(*returnSize, sizeof(int *));
    qsort(data, scoreSize, sizeof(DATA), sort);
    for (int i = 0; i < scoreSize; i++)
    {
        r[i] = score[data[i].index];
    }

    free(data);
    return r;
}

// @lc code=end