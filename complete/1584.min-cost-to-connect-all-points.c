/*
 * @lc app=leetcode id=1584 lang=c
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

typedef struct
{
    int len;
    int x;
    int y;
} EDGE;

int sort(EDGE *a, EDGE *b)
{
    return a->len - b->len;
}

int find(int *f, int x)
{
    return f[x] == x ? x : (f[x] = find(f, f[x]));
}

int unionSet(int *f, int *rank, int x, int y)
{
    int fx = find(f, x), fy = find(f, y);
    if (fx == fy)
        return false;

    if (rank[fx] < rank[fy])
        swap(&fx, &fy);

    rank[fx] += rank[fy];
    f[fy] = fx;
    return true;
}

int minCostConnectPoints(int **points, int pointsSize, int *pointsColSize)
{
    int n = pointsSize;
    EDGE edges[(n + 1) * n / 2];
    int edgesSize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            edges[edgesSize].x = i;
            edges[edgesSize].y = j;
            edges[edgesSize++].len = fabs(points[i][0] - points[j][0]) + fabs(points[i][1] - points[j][1]);
        }
    }
    qsort(edges, edgesSize, sizeof(EDGE), sort);
    int f[n], rank[n];
    for (int i = 0; i < n; i++)
    {
        f[i] = i;
        rank[i] = 1;
    }
    int ret = 0, num = 1;
    for (int i = 0; i < edgesSize; i++)
    {
        if (unionSet(f, rank, edges[i].x, edges[i].y))
        {
            ret += edges[i].len;
            num++;
            if (num == n)
                break;
        }
    }
    return ret;
}

// @lc code=end

// Note: union find . graph . minimum spanning tree
