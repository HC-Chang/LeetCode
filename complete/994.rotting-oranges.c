/*
 * @lc app=leetcode id=994 lang=c
 *
 * [994] Rotting Oranges
 */

// @lc code=start
typedef struct
{
    int capacity;
    int left;
    int right;
    int *arr;
} QUEUE;

QUEUE *init_queue(int capacity)
{
    QUEUE *q = malloc(sizeof(QUEUE));
    q->capacity = capacity;
    q->left = 0;
    q->right = 0;
    q->arr = calloc(3000 * capacity, sizeof(int));
    return q;
}

void push_queue(int i, int j, QUEUE *q)
{
    q->arr[q->right++] = i;
    q->arr[q->right++] = j;
}

void pop_queue(int *i, int *j, QUEUE *q)
{
    *i = q->arr[q->left++];
    *j = q->arr[q->left++];
}

int size_queue(QUEUE *q)
{
    return q->right - q->left;
}

void free_queue(QUEUE *q)
{
    free(q->arr);
    free(q);
}

int orangesRotting(int **grid, int gridSize, int *gridColSize)
{
    QUEUE *q = init_queue(gridSize * gridColSize[0]);
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[0]; j++)
        {
            if (grid[i][j] == 2)
                push_queue(i, j, q);
        }
    }

    int x, y;
    int a, b;
    int x_dir[4] = {-1, 0, 1, 0};
    int y_dir[4] = {0, 1, 0, -1};
    int count = 0;
    int tmp;
    while (size_queue(q))
    {
        for (int i = size_queue(q); i > 0 ; i-=2)
        {
            pop_queue(&x, &y, q);
            for (int j = 0; j < 4; j++)
            {
                a = x + x_dir[j];
                b = y + y_dir[j];
                if (a < 0 || a >= gridSize || b < 0 || b >= gridColSize[0] || grid[a][b] != 1)
                    continue;
                grid[a][b] = 2;
                push_queue(a, b, q);
            }
        }
        count++;
    }
    free_queue(q);

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[0]; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return 0 > count - 1 ? 0 : count - 1;
}
// @lc code=end
