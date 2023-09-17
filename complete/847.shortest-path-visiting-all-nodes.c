/*
 * @lc app=leetcode id=847 lang=c
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
int fullMask;
int dp[1 << 12][12];

int dfs(int nowNode, int nowMask, int **graph, int graphSize, int *graphColSize)
{
    if (dp[nowMask][nowNode] != -1)
        return dp[nowMask][nowNode];
    if (nowMask == fullMask)
        return 0;
    dp[nowMask][nowNode] = 1 << 28;

    int neighbor;
    for (int i = 0; i < graphColSize[nowNode]; i++)
    {
        neighbor = graph[nowNode][i];
        dp[nowMask][nowNode] = fmin(dp[nowMask][nowNode], fmin(dfs(neighbor, nowMask, graph, graphSize, graphColSize), dfs(neighbor, nowMask | (1 << neighbor), graph, graphSize, graphColSize)) + 1);
    }
    return dp[nowMask][nowNode];
}

int shortestPathLength(int **graph, int graphSize, int *graphColSize)
{
    int shortest = 1 << 28;
    int amount = graphSize;
    memset(dp, -1, sizeof(dp));
    fullMask = (1 << amount) - 1;
    for (int i = 0; i < amount; ++i)
        shortest = fmin(shortest, dfs(i, 1 << i, graph, graphSize, graphColSize));
    return shortest;
}
// @lc code=end

// Note: DP . BFS . graph