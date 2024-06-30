/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 */

// @lc code=start
class Solution
{
public:
    int find(vector<int> &p, int x) { return p[x] < 0 ? x : (p[x] = find(p, p[x])); }

    int connect(vector<int> &p, int x, int y)
    {
        int g = find(p, x), h = find(p, y);
        if (g == h)
            return 0;
        if (p[g] > p[h])
            p[g] = h;
        else if (p[h] > p[g])
            p[h] = g;
        else
        {
            p[g] = h;
            p[h] -= 1;
        }
        return 1;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {

        int e[] = {0, 0, 0}, c[] = {n, n, n};
        vector<vector<int>> p(3, vector<int>(n));
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < n; ++i)
                p[j][i] = -1;
        }

        int edgesSize = edges.size();
        for (int i = 0; i < edgesSize; ++i)
        {
            int t = edges[i][0] % 3, u = edges[i][1] % n, v = edges[i][2] % n;
            for (int j = t; j < (t ^ 1 | 2); ++j)
            {
                e[j] += 1;
                c[j] -= connect(p[j], u, v);
            }
        }
        return c[1] > 1 || c[2] > 1
                   ? -1
                   : e[1] + e[2] - e[0] + c[1] + c[2] - c[0] - n;
    }
};

// @lc code=end

// Official Solution - Union Find
