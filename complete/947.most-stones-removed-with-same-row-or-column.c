/*
 * @lc app=leetcode id=947 lang=c
 *
 * [947] Most Stones Removed with Same Row or Column
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

int removeStones(int **stones, int stonesSize, int *stonesColSize)
{
    if (stonesSize <= 1)
        return 0;
    UNION *u = union_find_init(stonesSize);
    for (int i = 0; i < stonesSize; i++)
    {
        for (int j = i + 1; j < stonesSize; j++)
        {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                union_p_q(i, j, u);
        }
    }

    int count = stonesSize - union_count(u);
    union_free(u);
    return count;
}
// @lc code=end
