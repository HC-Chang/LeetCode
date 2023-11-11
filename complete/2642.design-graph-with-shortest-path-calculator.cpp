/*
 * @lc app=leetcode id=2642 lang=cpp
 *
 * [2642] Design Graph With Shortest Path Calculator
 */

// @lc code=start
class Graph
{
    vector<vector<int>> distance;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        distance = vector<vector<int>>(n, vector<int>(n, INT_MAX / 3));
        for (int i = 0; i < n; ++i)
            distance[i][i] = 0;
        for (auto &e : edges)
            distance[e[0]][e[1]] = e[2];
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
    }

    void addEdge(vector<int> e)
    {
        int x = e[0], y = e[1], w = e[2], n = distance.size();
        if (w >= distance[x][y])
            return;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                distance[i][j] = min(distance[i][j], distance[i][x] + w + distance[y][j]);
    }

    int shortestPath(int start, int end)
    {
        int r = distance[start][end];
        return r < INT_MAX / 3 ? r : -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end

// Note: graph + heap