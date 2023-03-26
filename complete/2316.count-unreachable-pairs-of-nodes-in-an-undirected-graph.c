/*
 * @lc app=leetcode id=2316 lang=c
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph

 */

// @lc code=start
typedef struct
{
    int count;
    int *parent;
    unsigned int *size;
} UNION;

UNION *union_find_init(int n)
{
    UNION *u = malloc(sizeof(UNION));
    u->count = n;
    u->parent = malloc(n * sizeof(int));
    u->size = malloc(n * sizeof(unsigned int));
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

void union_free(UNION *u)
{
    free(u->parent);
    free(u->size);
    free(u);
}

long long countPairs(int n, int **edges, int edgesSize, int *edgesColSize)
{
    UNION *u = union_find_init(n);

    for (int i = 0; i < edgesSize; i++)
        union_p_q(edges[i][0], edges[i][1], u);

    long long count = 0;
    for (int i = 0; i < n; i++)
        count += n - u->size[find(i, u)];
    union_free(u);
    return count / 2;
}
// @lc code=end
