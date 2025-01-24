/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution
{
public:
    bool helper(vector<vector<int>> &graph, int cur, vector<int> &status)
    {
        if (status[cur] > 0)
            return status[cur] == 2;
        status[cur] = 1;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            if (status[graph[cur][i]] == 2)
                continue;
            if (status[graph[cur][i]] == 1 ||
                !helper(graph, graph[cur][i], status))
                return false;
        }
        status[cur] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> res;
        int graphSize = graph.size();
        vector<int> status(graphSize);
        for (int i = 0; i < graphSize; ++i)
        {
            if (helper(graph, i, status))
                res.push_back(i);
        }

        return res;
    }
};
// @lc code=end

// Note: topological sort