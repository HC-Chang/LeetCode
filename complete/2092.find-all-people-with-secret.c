/*
 * @lc app=leetcode id=2092 lang=c
 *
 * [2092] Find All People With Secret
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int sort(void *a, void *b)
{
    int **x = (int **)a;
    int **y = (int **)b;
    if (x[0][2] == y[0][2])
        return x[0][0] - y[0][0];
    return x[0][2] - y[0][2];
}

void push_arr(int val, int *idx, int *arr)
{
    arr[(*idx)++] = val;
}

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

bool is_connected(int p, int q, UNION *u)
{
    int root_p = find(p, u);
    int root_q = find(q, u);
    return root_p == root_q;
}

void union_set(int val, UNION *u)
{
    u->parent[val] = val;
    u->size[val] = 1;
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

int *findAllPeople(int n, int **meetings, int meetingsSize, int *meetingsColSize, int firstPerson, int *returnSize)
{
    qsort(meetings, meetingsSize, sizeof(int *), sort);

    UNION *u = union_find_init(n);
    union_p_q(0, firstPerson, u);

    int time;
    int j;
    for (int i = 0; i < meetingsSize; i++)
    {
        time = meetings[i][2];
        union_p_q(meetings[i][0], meetings[i][1], u);

        if (i == meetingsSize - 1 || meetings[i][2] != meetings[i + 1][2])
        {
            j = i;

            while (j >= 0 && meetings[j][2] == time)
            {
                if (!is_connected(0, meetings[j][1], u))
                    union_set(meetings[j][1], u);
                if (!is_connected(0, meetings[j][0], u))
                    union_set(meetings[j][0], u);
                --j;
            }
        }
    }

    int *arr = malloc(n * sizeof(int));
    *returnSize = 0;
    push_arr(0, returnSize, arr);
    for (int i = 1; i < n; i++)
    {
        if (is_connected(0, i, u))
            push_arr(i, returnSize, arr);
    }
    union_free(u);

    return arr;
}
// @lc code=end

// Note: sorting + (BFS / union find)