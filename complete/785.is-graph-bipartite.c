/*
 * @lc app=leetcode id=785 lang=c
 *
 * [785] Is Graph Bipartite?
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

bool isBipartite(int **graph, int graphSize, int *graphColSize)
{
    UNION *u = union_find_init(graphSize);
    int x, y, parent;
    for (int i = 0; i < graphSize; i++)
    {
        if (graphColSize[i] == 0)
            continue;
        x = find(i, u);
        y = find(graph[i][0], u);
        if (x == y)
        {
            union_free(u);
            return false;
        }
        for (int j = 1; j < graphColSize[i]; j++)
        {
            parent = find(graph[i][j], u);
            if (x == parent)
            {
                union_free(u);
                return false;
            }
            union_p_q(parent, y, u);
        }
    }
    union_free(u);
    return true;
}
// @lc code=end
