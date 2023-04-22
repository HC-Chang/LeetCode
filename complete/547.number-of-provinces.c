/*
 * @lc app=leetcode id=547 lang=c
 *
 * [547] Number of Provinces
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

int union_count(UNION *u)
{
    return u->count;
}

void union_free(UNION *u)
{
    free(u->parent);
    free(u->size);
    free(u);
}

int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize)
{
    UNION *u = union_find_init(isConnectedSize);
    for (int i = 0; i < isConnectedSize; i++)
    {
        for (int j = i + 1; j < isConnectedSize; j++)
        {
            if (isConnected[i][j] == 1)
                union_p_q(i, j, u);
        }
    }
    int count = union_count(u);
    union_free(u);
    return count;
}
// @lc code=end

// Note: union-find