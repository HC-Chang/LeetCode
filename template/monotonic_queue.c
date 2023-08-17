// Monotonic Queue
// Similar Questions: 239

// monotonic queue api:
// - init
// - is_empty
// - push
// - pop
// - top
// - free

typedef struct
{
    int capacity;
    int *arr;
    int head;
    int tail;
} MonotonicQueue;

MonotonicQueue *init_monotonic_queue(int capacity)
{
    MonotonicQueue *obj = malloc(sizeof(MonotonicQueue));
    obj->capacity = capacity;
    obj->arr = malloc(capacity * sizeof(int));
    obj->head = 0;
    obj->tail = -1;
    return obj;
}

int is_empty_monotonic_queue(MonotonicQueue *obj)
{
    return obj->tail < obj->head;
}

void push_monotonic_queue(int val, MonotonicQueue *obj)
{
    while (!is_empty_monotonic_queue(obj) && val > obj->arr[obj->tail])
        obj->tail--;

    obj->tail++;
    obj->arr[obj->tail] = val;
}

void pop_monotonic_queue(MonotonicQueue *obj)
{
    obj->head++;
}

int top_monotonic_queue(MonotonicQueue *obj)
{
    return obj->arr[obj->head];
}

void free_monotonic_queue(MonotonicQueue *obj)
{
    free(obj->arr);
    free(obj);
}