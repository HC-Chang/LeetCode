/*
 * @lc app=leetcode id=1631 lang=c
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
typedef struct
{
    int x, y;
} POS;

typedef struct
{
    POS *pos_arr;
    int push_index;
    int pop_index;
    int capacity;
} QUEUE;

QUEUE *init_queue(int capacity)
{
    QUEUE *obj = calloc(1, sizeof(QUEUE));
    obj->capacity = capacity;
    obj->pos_arr = calloc(capacity, sizeof(QUEUE));
    return obj;
}

void push_queue(int x, int y, QUEUE *obj)
{
    obj->pos_arr[obj->push_index].x = x;
    obj->pos_arr[obj->push_index++].y = y;
}

void pop_queue(QUEUE *obj)
{
    obj->pop_index++;
}

POS top_queue(QUEUE *obj)
{
    return obj->pos_arr[obj->pop_index];
}

bool is_empty_queue(QUEUE *obj)
{
    return obj->push_index - obj->pop_index > 0 ? false : true;
}

void free_queue(QUEUE *obj)
{
    free(obj->pos_arr);
    free(obj);
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool connected(int **heights, int heightsSize, int *heightsColSize, int limit)
{
    int m = heightsSize;
    int n = heightsColSize[0];

    if (m == 1 && n == 1)
        return true;

    bool visited[m][n];
    memset(visited, 0, m * n * sizeof(bool));
    QUEUE *q = init_queue(m * n);

    push_queue(0, 0, q);
    visited[0][0] = true;

    while (!is_empty_queue(q))
    {
        POS tmp = top_queue(q);
        int x = tmp.x;
        int y = tmp.y;
        pop_queue(q);

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && abs(heights[x][y] - heights[nx][ny]) <= limit)
            {
                if (nx == m - 1 && ny == n - 1)
                {
                    free_queue(q);
                    return true;
                }
                push_queue(nx, ny, q);
                visited[nx][ny] = true;
            }
        }
    }
    free_queue(q);
    return false;
}

int minimumEffortPath(int **heights, int heightsSize, int *heightsColSize)
{
    int l = 0, r = 1e6 - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (connected(heights, heightsSize, heightsColSize, mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
// @lc code=end
