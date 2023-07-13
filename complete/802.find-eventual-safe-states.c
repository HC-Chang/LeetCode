/*
 * @lc app=leetcode id=802 lang=c
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void push_arr(int val, int *index, int *arr)
{
    arr[(*index)++] = val;
}

bool helper(int **graph, int *graphColSize, int cur, int *status)
{
    if (status[cur] > 0)
        return status[cur] == 2;
    status[cur] = 1;
    for (int i = 0; i < graphColSize[cur]; i++)
    {
        if (status[graph[cur][i]] == 2)
            continue;
        if (status[graph[cur][i]] == 1 || !helper(graph, graphColSize, graph[cur][i], status))
            return false;
    }
    status[cur] = 2;
    return true;
}

int *eventualSafeNodes(int **graph, int graphSize, int *graphColSize, int *returnSize)
{
    *returnSize = 0;
    int *res = calloc(graphSize, sizeof(int));
    int *status = calloc(graphSize, sizeof(int));
    for (int i = 0; i < graphSize; ++i)
    {
        if (helper(graph, graphColSize, i, status))
            push_arr(i, returnSize, res);
    }

    free(status);
    return res;
}
// @lc code=end

// Note: topological sort