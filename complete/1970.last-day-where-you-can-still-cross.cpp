/*
 * @lc app=leetcode id=1970 lang=cpp
 *
 * [1970] Last Day Where You Can Still Cross
 */

// @lc code=start
class DSU
{
    vector<int> parent;
    vector<int> p_size;

public:
    DSU(int n) : parent(n), p_size(n, 1)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (p_size[a] < p_size[b])
            swap(a, b);
        parent[b] = a;
        p_size[a] += p_size[b];
    }

    bool same(int a, int b) { return find(a) == find(b); }
};

class Solution
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int n = row * col;
        DSU dsu(n + 2);
        int top = n, bottom = n + 1;
        vector<vector<char>> grid(row, vector<char>(col, 0));
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int t = (int)cells.size() - 1; t >= 0; --t)
        {
            int r = cells[t][0] - 1;
            int c = cells[t][1] - 1;
            grid[r][c] = 1;
            int id = r * col + c;
            if (r == 0)
                dsu.unite(id, top);
            if (r == row - 1)
                dsu.unite(id, bottom);
            for (int k = 0; k < 4; k++)
            {
                int x = r + dirs[k][0], y = c + dirs[k][1];
                if (x < 0 || x >= row || y < 0 || y >= col)
                    continue;
                if (grid[x][y])
                    dsu.unite(id, x * col + y);
            }
            if (dsu.same(top, bottom))
                return t;
        }
        return 0;
    }
};
// @lc code=end

// Note: union find