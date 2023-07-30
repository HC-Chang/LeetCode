/*
 * @lc app=leetcode id=1926 lang=c
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
typedef struct
{
    int capacity;
    int push_idx;
    int pop_idx;
    int *x;
    int *y;
} QUEUE;

QUEUE *init_queue(int n)
{
    QUEUE *obj = calloc(1, sizeof(QUEUE));
    obj->capacity = n;
    obj->x = calloc(n, sizeof(int));
    obj->y = calloc(n, sizeof(int));
    return obj;
}

void push_queue(int x, int y, QUEUE *obj)
{
    obj->x[obj->push_idx] = x;
    obj->y[obj->push_idx++] = y;
}
void pop_queue(QUEUE *obj)
{
    obj->pop_idx++;
}
int top_x_queue(QUEUE *obj)
{
    return obj->x[obj->pop_idx];
}
int top_y_queue(QUEUE *obj)
{
    return obj->y[obj->pop_idx];
}
int size_queue(QUEUE *obj)
{
    return obj->push_idx - obj->pop_idx;
}
bool is_empty_queue(QUEUE *obj)
{
    return (obj->push_idx - obj->pop_idx) == 0;
}
void free_queue(QUEUE *obj)
{
    free(obj->x);
    free(obj->y);
    free(obj);
}

int nearestExit(char **maze, int mazeSize, int *mazeColSize, int *entrance, int entranceSize)
{
    int dirs[5] = {0, -1, 0, 1, 0};
    QUEUE *q = init_queue(10000);
    int x, y, tx, ty;
    push_queue(entrance[1], entrance[0], q);
    for (int steps = 0; !is_empty_queue(q); ++steps)
    {
        for (int s = size_queue(q); s; --s)
        {
            x = top_x_queue(q);
            y = top_y_queue(q);
            pop_queue(q);
            if (x == 0 || x == mazeColSize[0] - 1 || y == 0 || y == mazeSize - 1)
                if (x != entrance[1] || y != entrance[0])
                {
                    free_queue(q);
                    return steps;
                }
            for (int i = 0; i < 4; ++i)
            {
                tx = x + dirs[i];
                ty = y + dirs[i + 1];
                if (tx < 0 || tx >= mazeColSize[0] || ty < 0 || ty >= mazeSize || maze[ty][tx] != '.')
                    continue;
                maze[ty][tx] = '*';
                push_queue(tx, ty, q);
            }
        }
    }
    free_queue(q);
    return -1;
}
// @lc code=end

// Note: BFS