/*
 * @lc app=leetcode id=1557 lang=c
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSmallestSetOfVertices(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
    int *parent = calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++)
        ++parent[edges[i][1]];
    *returnSize = 0;
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == 0)
            arr[(*returnSize)++] = i;
    }
    free(parent);
    arr = realloc(arr, (*returnSize) * sizeof(int));
    return arr;
}
// @lc code=end
