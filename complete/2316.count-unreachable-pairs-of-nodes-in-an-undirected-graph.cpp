/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph

 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<int> adj[], int src, vector<bool> &vis, int &counter)
    {
        if (vis[src])
            return;
        vis[src] = true;
        counter++;
        for (auto ele : adj[src])
        {
            if (!vis[ele])
            {
                dfs(adj, ele, vis, counter);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n];
        for (auto element : edges)
        {
            adj[element[0]].push_back(element[1]);
            adj[element[1]].push_back(element[0]);
        }
        long long res = 0;
        vector<bool> visited(n, false);
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int counter = 0;
                dfs(adj, i, visited, counter);
                temp.push_back(counter);
            }
        }
        int total = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            res += (long)((long)temp[i] * (long)(n - total - temp[i]));
            total += temp[i];
        }
        return res;
    }
};

// @lc code=end
