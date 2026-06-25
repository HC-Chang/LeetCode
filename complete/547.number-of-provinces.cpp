/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class UnionFind
{
    vector<int> parent, rank;
    int count;

public:
    UnionFind(int n) : count(n), parent(n), rank(n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int p, int q)
    {
        int rootP = find(p), rootQ = find(q);
        if (rootP == rootQ)
            return;
        if (rank[rootP] > rank[rootQ])
            swap(rootP, rootQ);
        parent[rootP] = rootQ;
        rank[rootQ] += rank[rootP];
        count--;
    }

    int size() const { return count; }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isConnected[i][j])
                    uf.unite(i, j);
        return uf.size();
    }
};
// @lc code=end

// Note: union-find