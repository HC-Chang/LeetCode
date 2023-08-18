/*
 * @lc app=leetcode id=1615 lang=c
 *
 * [1615] Maximal Network Rank
 */

// @lc code=start
int maximalNetworkRank(int n, int **roads, int roadsSize, int *roadsColSize)
{
    if (roadsSize == 0)
        return 0;

    int res = INT_MIN;
    int rank = INT_MIN;
    int *edges = calloc(n + 1, sizeof(int));
    bool adj[n + 1][n + 1];
    memset(adj, 0, (n + 1) * (n + 1) * sizeof(bool));
    int from;
    int to;
    for (int i = 0; i < roadsSize; i++)
    {
        from = roads[i][0];
        to = roads[i][1];
        edges[from]++;
        edges[to]++;
        adj[from][to] = true;
        adj[to][from] = true;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            rank = edges[i] + edges[j] - (adj[i][j] == true ? 1 : 0);
            res = fmax(res, rank);
        }
    }

    free(edges);
    return res;
}
// @lc code=end

// Note: graph