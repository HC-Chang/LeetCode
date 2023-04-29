/*
 * @lc app=leetcode id=1697 lang=c
 *
 * [1697] Checking Existence of Edge Length Limited Paths
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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

int find(int x, UNION *u)
{
    while (u->parent[x] != x)
    {
        u->parent[x] = u->parent[u->parent[x]];
        x = u->parent[x];
    }
    return x;
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

void union_free(UNION *u)
{
    free(u->parent);
    free(u->size);
    free(u);
}

int sort(void **a, void **b)
{
    int *a1 = (int **)a[0];
    int *b1 = (int **)b[0];
    return a1[2] - b1[2];
}

bool *distanceLimitedPathsExist(int n, int **edgeList, int edgeListSize, int *edgeListColSize, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
    for (int i = 0; i < queriesSize; i++)
    {
        queries[i] = realloc(queries[i], 4 * sizeof(int));
        queries[i][3] = i;
    }

    qsort(edgeList, edgeListSize, sizeof(int *), sort);
    qsort(queries, queriesSize, sizeof(int *), sort);

    UNION *u = union_find_init(n);

    *returnSize = queriesSize;
    bool *r = calloc(*returnSize, sizeof(bool));
    int count = 0;
    int index;
    int p, q;
    for (int i = 0; i < queriesSize; i++)
    {
        while (count < edgeListSize && edgeList[count][2] < queries[i][2])
        {
            p = edgeList[count][0];
            q = edgeList[count][1];
            if (find(p, u) != find(q, u))
                union_p_q(p, q, u);
            count++;
        }

        index = queries[i][3];
        r[index] = (find(queries[i][0], u) == find(queries[i][1], u));
    }
    union_free(u);
    return r;
}
// @lc code=end
