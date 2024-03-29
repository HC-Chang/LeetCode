/*
 * @lc app=leetcode id=1489 lang=c
 *
 * [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

struct Edge
{
    int x, y, w, id;
};

int cmp(const void *a, const void *b)
{
    return ((struct Edge *)a)->w - ((struct Edge *)b)->w;
}

struct DisjointSetUnion
{
    int *f, *size;
    int n, setCount;
};

void initDSU(struct DisjointSetUnion *obj, int n)
{
    obj->f = malloc(sizeof(int) * n);
    obj->size = malloc(sizeof(int) * n);
    obj->n = n;
    obj->setCount = n;
    for (int i = 0; i < n; i++)
    {
        obj->f[i] = i;
        obj->size[i] = 1;
    }
}

void freeDSU(struct DisjointSetUnion *obj)
{
    free(obj->f);
    free(obj->size);
    free(obj);
}

int find(struct DisjointSetUnion *obj, int x)
{
    return obj->f[x] == x ? x : (obj->f[x] = find(obj, obj->f[x]));
}

int unionSet(struct DisjointSetUnion *obj, int x, int y)
{
    int fx = find(obj, x), fy = find(obj, y);
    if (fx == fy)
        return false;

    if (obj->size[fx] < obj->size[fy])
        swap(&fx, &fy);

    obj->size[fx] += obj->size[fy];
    obj->f[fy] = fx;
    obj->setCount--;
    return true;
}

int **findCriticalAndPseudoCriticalEdges(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize, int **returnColumnSizes)
{
    int m = edgesSize;
    struct Edge edgesTmp[m];
    for (int i = 0; i < m; i++)
    {
        edgesTmp[i].x = edges[i][0];
        edgesTmp[i].y = edges[i][1];
        edgesTmp[i].w = edges[i][2];
        edgesTmp[i].id = i;
    }
    qsort(edgesTmp, m, sizeof(struct Edge), cmp);

    struct DisjointSetUnion *ufStd = malloc(sizeof(struct DisjointSetUnion));
    initDSU(ufStd, n);

    int value = 0;
    for (int i = 0; i < m; ++i)
    {
        if (unionSet(ufStd, edgesTmp[i].x, edgesTmp[i].y))
            value += edgesTmp[i].w;
    }
    freeDSU(ufStd);

    *returnSize = 2;
    int **ans = malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++)
        ans[i] = malloc(sizeof(int) * m);

    *returnColumnSizes = malloc(sizeof(int) * 2);
    memset(*returnColumnSizes, 0, sizeof(int) * 2);

    for (int i = 0; i < m; ++i)
    {
        struct DisjointSetUnion *uf1 = malloc(sizeof(struct DisjointSetUnion));
        initDSU(uf1, n);

        int v = 0;
        for (int j = 0; j < m; ++j)
        {
            if (i != j && unionSet(uf1, edgesTmp[j].x, edgesTmp[j].y))
                v += edgesTmp[j].w;
        }
        if (uf1->setCount != 1 || (uf1->setCount == 1 && v > value))
        {
            ans[0][(*returnColumnSizes)[0]++] = edgesTmp[i].id;
            continue;
        }
        freeDSU(uf1);

        struct DisjointSetUnion *uf2 = malloc(sizeof(struct DisjointSetUnion));
        initDSU(uf2, n);
        unionSet(uf2, edgesTmp[i].x, edgesTmp[i].y);
        v = edgesTmp[i].w;
        for (int j = 0; j < m; ++j)
        {
            if (i != j && unionSet(uf2, edgesTmp[j].x, edgesTmp[j].y))
                v += edgesTmp[j].w;
        }
        if (v == value)
            ans[1][(*returnColumnSizes)[1]++] = edgesTmp[i].id;
    }
    return ans;
}
// @lc code=end

// Official Solution

// Note: union find . minimum spanning tree