/*
 * @lc app=leetcode id=1319 lang=c
 *
 * [1319] Number of Operations to Make Network Connected
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

void union_p_q(int p, int q, int *res, UNION *u)
{
    int root_p = find(p, u);
    int root_q = find(q, u);
    if (root_p == root_q)
        return;
    else
        --*res;
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

int makeConnected(int n, int **connections, int connectionsSize, int *connectionsColSize)
{
    if (n - 1 > connectionsSize)
        return -1;
    int res = n;
    UNION *u = union_find_init(n);
    for (int i = 0; i < connectionsSize; i++)
        union_p_q(connections[i][0], connections[i][1], &res, u);

    return res - 1;
}
// @lc code=end

// Note: Union-Find