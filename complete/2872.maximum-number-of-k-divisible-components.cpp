/*
 * @lc app=leetcode id=2872 lang=cpp
 *
 * [2872] Maximum Number of K-Divisible Components
 */

// @lc code=start
class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k)
    {
        if (n < 2)
            return 1;

        int componentCount = 0;
        vector<vector<int>> graph(n);
        vector<int> in_degree(n, 0);

        for (const auto &edge : edges)
        {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            in_degree[node1]++;
            in_degree[node2]++;
        }

        vector<long long> long_values(values.begin(), values.end());

        queue<int> queue;
        for (int node = 0; node < n; node++)
        {
            if (in_degree[node] == 1)
                queue.push(node);
        }

        while (!queue.empty())
        {
            int currentNode = queue.front();
            queue.pop();
            in_degree[currentNode]--;

            long long addValue = 0;

            if (long_values[currentNode] % k == 0)
                componentCount++;
            else
                addValue = long_values[currentNode];

            for (int neighborNode : graph[currentNode])
            {
                if (in_degree[neighborNode] == 0)
                    continue;

                in_degree[neighborNode]--;
                long_values[neighborNode] += addValue;

                if (in_degree[neighborNode] == 1)
                    queue.push(neighborNode);
            }
        }

        return componentCount;
    }
};
// @lc code=end

// Note: tree + dfs

// Official Solution