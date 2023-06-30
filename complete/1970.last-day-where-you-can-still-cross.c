/*
 * @lc app=leetcode id=1970 lang=c
 *
 * [1970] Last Day Where You Can Still Cross
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

int latestDayToCross(int row, int col, int **cells, int cellsSize, int *cellsColSize)
{
    UNION *u = union_find_init(row * col + 2);

    int **mat = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
        mat[i] = malloc(col * sizeof(int));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            mat[i][j] = 1;
    }

    for (int i = 0; i < cellsSize; i++)
        mat[cells[i][0] - 1][cells[i][1] - 1] = 0;

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
                continue;

            for (int k = 0; k < 4; k++)
            {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if (x < 0 || x >= row || y < 0 || y >= col)
                    continue;
                if (mat[x][y] == 0)
                    continue;

                if (find(i * col + j, u) != find(x * col + y, u))
                    union_p_q(i * col + j, x * col + y, u);
            }
        }

    for (int j = 0; j < col; j++)
        union_p_q(row * col, 0 * col + j, u);

    for (int j = 0; j < col; j++)
        union_p_q(row * col + 1, (row - 1) * col + j, u);

    for (int t = cellsSize - 1; t >= 0; t--)
    {
        if (find(row * col, u) == find(row * col + 1, u))
        {
            for (int i = 0; i < row; i++)
                free(mat[i]);
            free(mat);
            union_free(u);
            return t + 1;
        }

        int i = cells[t][0] - 1;
        int j = cells[t][1] - 1;
        mat[i][j] = 1;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if (x < 0 || x >= row || y < 0 || y >= col)
                continue;
            if (mat[x][y] == 0)
                continue;

            if (find(i * col + j, u) != find(x * col + y, u))
                union_p_q(i * col + j, x * col + y, u);
        }
    }

    for (int i = 0; i < row; i++)
        free(mat[i]);
    free(mat);
    union_free(u);
    return 0;
}
// @lc code=end
