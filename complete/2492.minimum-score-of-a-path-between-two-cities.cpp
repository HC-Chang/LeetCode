/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */

// @lc code=start
class UnionFind
{
public:
    explicit UnionFind(int n)
        : parent(n + 1), size(n + 1, 1)
    {
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y)
            return;
        if (size[root_x] < size[root_y])
            swap(root_x, root_y);
        parent[root_y] = root_x;
        size[root_x] += size[root_y];
    }

private:
    vector<int> parent;
    vector<int> size;
};

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        UnionFind uf(n);
        for (const auto &road : roads)
            uf.unite(road[0], road[1]);

        int root1 = uf.find(1);
        int result = INT_MAX;
        for (const auto &road : roads)
        {
            if (uf.find(road[0]) == root1)
                result = std::min(result, road[2]);
        }
        return result;
    }
};
// @lc code=end

// Note: Union-Find