/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
class Solution
{
public:
    void traverse(vector<vector<int>> &tree, int cur, int pre, vector<int> &count,
                  vector<int> &res)
    {
        for (int i : tree[cur])
        {
            if (i == pre)
                continue;
            traverse(tree, i, cur, count, res);
            count[cur] += count[i];
            res[cur] += res[i] + count[i];
        }
        ++count[cur];
    }

    void lens(vector<vector<int>> &tree, int cur, int pre,
              vector<int> &count, vector<int> &res)
    {
        for (int i : tree[cur])
        {
            if (i == pre)
                continue;
            res[i] = res[cur] - count[i] + count.size() - count[i];
            lens(tree, i, cur, count, res);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<int> res(n);
        vector<int> count(n);
        vector<vector<int>> tree(n);
        for (auto &edge : edges)
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        traverse(tree, 0, -1, count, res);
        lens(tree, 0, -1, count, res);
        return res;
    }
};
// @lc code=end

// Note: DP +DFS