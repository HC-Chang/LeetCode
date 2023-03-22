/*
 * @lc app=leetcode id=2492 lang=c
 *
 * [2492] Minimum Score of a Path Between Two Cities
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
        u->size[i] = i;
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

int find_father(int x, UNION *u)
{
    if (u->parent[x] != x)
        u->parent[x] = find_father(u->parent[x], u);
    return u->parent[x];
}

void union_free(UNION *u)
{
    free(u->parent);
    free(u->size);
    free(u);
}

int min(int a, int b) { return a < b ? a : b; }

int minScore(int n, int **roads, int roadsSize, int *roadsColSize)
{
    UNION *u = union_find_init(100001);
    for (int i = 0; i < roadsSize; i++)
        union_p_q(roads[i][0], roads[i][1], u);

    int r = INT_MAX;
    for (int i = 0; i < roadsSize; i++)
    {
        if (find_father(roads[i][0], u) == find_father(1, u))
            r = min(r, roads[i][2]);
    }
    union_free(u);
    return r;
}

// @lc code=end
