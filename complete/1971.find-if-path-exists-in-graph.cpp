/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution
{
public:
    typedef struct
    {
        int count;
        int *parent;
        unsigned int *size;
    } UNION;

    UNION *union_find_init(int n)
    {
        UNION *u = (UNION *)malloc(sizeof(UNION));
        u->count = n;
        u->parent = (int *)malloc(n * sizeof(int));
        u->size = (unsigned int *)malloc(n * sizeof(unsigned int));
        for (int i = 0; i < n; i++)
        {
            u->parent[i] = i;
            u->size[i] = 1;
        }
        return u;
    }

    void union_p_q(int p, int q, UNION *u)
    {
        int root_p = find(p, u);
        int root_q = find(q, u);
        if (root_p == root_q)
            return;
        if (u->size[root_p] > u->size[root_q])
        {
            u->parent[root_q] = root_p;
            u->size[root_p] += u->size[root_q];
        }
        else
        {
            u->parent[root_p] = root_q;
            u->size[root_q] += u->size[root_p];
        }
        u->count--;
    }

    int find(int x, UNION *u)
    {
        while (u->parent[x] != x)
        {
            u->parent[x] = u->parent[u->parent[x]];
            x = u->parent[x];
        }
        return x;
    }

    bool is_connected(int p, int q, UNION *u)
    {
        int root_p = find(p, u);
        int root_q = find(q, u);
        return root_p == root_q;
    }

    void union_free(UNION *u)
    {
        free(u->parent);
        free(u->size);
        free(u);
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        UNION *u = union_find_init(n);
        for (int i = 0; i < edges.size(); i++)
            union_p_q(edges[i][0], edges[i][1], u);

        bool b = is_connected(source, destination, u);
        union_free(u);
        return b;
    }
};
// @lc code=end

// Note: union-find