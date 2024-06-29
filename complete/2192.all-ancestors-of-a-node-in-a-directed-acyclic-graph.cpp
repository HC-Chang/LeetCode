/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
class Solution
{
public:
    void dfs(int s, int u, vector<vector<int>> &parent, vector<vector<int>> &ans)
    {
        for (auto v : parent[u])
        {
            if (ans[v].empty() || ans[v].back() != s)
            {
                ans[v].push_back(s);
                dfs(s, v, parent, ans);
            }
        }
    };
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> ans(n);
        vector<vector<int>> parent(n);
        for (const auto &e : edges)
            parent[e[0]].push_back(e[1]);

        for (int i = 0; i < n; i++)
            dfs(i, i, parent, ans);
        return ans;
    }
};
// @lc code=end

// Note: DFS