/*
 * @lc app=leetcode id=2642 lang=c
 *
 * [2642] Design Graph With Shortest Path Calculator
 */

// @lc code=start
typedef struct
{
    int distance[101][101];
} Graph;

Graph *graphCreate(int n, int **edges, int edgesSize, int *edgesColSize)
{
    Graph *obj = malloc(sizeof(Graph));
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (i == j)
                obj->distance[i][j] = 0;
            else
                obj->distance[i][j] = INT_MAX / 3;
        }
    }

    for (int i = 0; i < edgesSize; i++)
        obj->distance[edges[i][0]][edges[i][1]] = edges[i][2];
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                obj->distance[i][j] = fmin(obj->distance[i][j], obj->distance[i][k] + obj->distance[k][j]);

    return obj;
}

void graphAddEdge(Graph *obj, int *edge, int edgeSize)
{
    int x = edge[0], y = edge[1], w = edge[2];
    if (w >= obj->distance[x][y])
        return;
    for (int i = 0; i < 101; ++i)
        for (int j = 0; j < 101; ++j)
            obj->distance[i][j] = fmin(obj->distance[i][j], obj->distance[i][x] + w + obj->distance[y][j]);
}

int graphShortestPath(Graph *obj, int node1, int node2)
{
    int ans = obj->distance[node1][node2];
    return ans < INT_MAX / 3 ? ans : -1;
}

void graphFree(Graph *obj)
{
    free(obj);
}

/**
 * Your Graph struct will be instantiated and called as such:
 * Graph* obj = graphCreate(n, edges, edgesSize, edgesColSize);
 * graphAddEdge(obj, edge, edgeSize);
 * int param_2 = graphShortestPath(obj, node1, node2);
 * graphFree(obj);
*/
// @lc code=end

// Note: graph + heap