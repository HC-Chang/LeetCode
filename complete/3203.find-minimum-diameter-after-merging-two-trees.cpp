/*
 * @lc app=leetcode id=3203 lang=cpp
 *
 * [3203] Find Minimum Diameter After Merging Two Trees
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> connect(int size, vector<vector<int>> &edges)
    {
        vector<vector<int>> list(size);
        for (auto &edge : edges)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        return list;
    }

    int find_diameter(int n, vector<vector<int>> &list)
    {
        queue<int> leaves_queue;
        vector<int> degrees(n);
        for (int node = 0; node < n; node++)
        {
            degrees[node] = list[node].size();
            if (degrees[node] == 1)
                leaves_queue.push(node);
        }

        int remaining_nodes = n;
        int leaves_layers_removed = 0;

        while (remaining_nodes > 2)
        {
            int size = leaves_queue.size();
            remaining_nodes -= size;
            leaves_layers_removed++;

            for (int i = 0; i < size; i++)
            {
                int currentNode = leaves_queue.front();
                leaves_queue.pop();

                for (int neighbor : list[currentNode])
                {
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1)
                        leaves_queue.push(neighbor);
                }
            }
        }

        if (remaining_nodes == 2)
            return 2 * leaves_layers_removed + 1;

        return 2 * leaves_layers_removed;
    }

    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj_list1 = connect(n, edges1);
        vector<vector<int>> adj_list2 = connect(m, edges2);

        int diameter1 = find_diameter(n, adj_list1);
        int diameter2 = find_diameter(m, adj_list2);
        int combinedDiameter = ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        return max({diameter1, diameter2, combinedDiameter});
    }
};
// @lc code=end

// Note: graph + dfs

// Official Solution