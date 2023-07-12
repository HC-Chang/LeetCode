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

bool helper(int **graph, int *graphColSize, int cur, int *color)
{
    if (color[cur] > 0)
        return color[cur] == 2;
    color[cur] = 1;
    for (int i = 0; i < graphColSize[cur]; i++)
    {
        if (color[graph[cur][i]] == 2)
            continue;
        if (color[graph[cur][i]] == 1 || !helper(graph, graphColSize, graph[cur][i], color))
            return false;
    }
    color[cur] = 2;
    return true;
}

int *eventualSafeNodes(int **graph, int graphSize, int *graphColSize, int *returnSize)
{
    *returnSize = 0;
    int *res = calloc(graphSize, sizeof(int));
    int *color = calloc(graphSize, sizeof(int));
    for (int i = 0; i < graphSize; ++i)
    {
        if (helper(graph, graphColSize, i, color))
            push_arr(i, returnSize, res);
    }

    free(color);
    return res;
}
// @lc code=end

// Note: topological sort