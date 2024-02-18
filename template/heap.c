// Heap
// Similar Questions: 1845 (min)

typedef struct
{
    int size;
    int *arr;
} HEAP;

// heap
HEAP *init_heap(int n)
{
    HEAP *obj = malloc(sizeof(HEAP));
    obj->size = 0;
    obj->arr = calloc(n, sizeof(int));

    return obj;
}

void free_heap(HEAP *obj)
{
    free(obj->arr);
    free(obj);
}

// min-heap
void push_min_heap(int val, HEAP *obj)
{
    obj->arr[obj->size++] = val;
    int lower = obj->size - 1;
    int upper = (lower + 1) / 2 - 1;
    int tmp;
    while (upper >= 0)
    {
        if (lower + 1 < obj->size && obj->arr[lower + 1] < obj->arr[lower])
            lower++;
        if (obj->arr[lower] > obj->arr[upper])
            break;
        if (obj->arr[upper] > obj->arr[lower])
        {
            tmp = obj->arr[upper];
            obj->arr[upper] = obj->arr[lower];
            obj->arr[lower] = tmp;
        }
        lower = upper;
        upper = (lower + 1) / 2 - 1;
    }
}

int pop_min_heap(HEAP *obj)
{
    int r = obj->arr[0];
    obj->arr[0] = obj->arr[--obj->size];
    int n = obj->size;
    int upper = 0;
    int lower = 2 * upper + 1;
    int tmp;
    while (lower < n)
    {
        if (lower + 1 < n && obj->arr[lower + 1] < obj->arr[lower])
            lower++;
        if (obj->arr[lower] > obj->arr[upper])
            break;
        if (obj->arr[upper] > obj->arr[lower])
        {
            tmp = obj->arr[upper];
            obj->arr[upper] = obj->arr[lower];
            obj->arr[lower] = tmp;
        }
        upper = lower;
        lower = upper * 2 + 1;
    }
    return r;
}

// max-heap
void push_max_heap(int val, HEAP *obj)
{
    obj->arr[obj->size++] = val;
    int lower = obj->size - 1;
    int upper = (lower + 1) / 2 - 1;
    int tmp;
    while (upper >= 0)
    {
        if (lower + 1 < obj->size && obj->arr[lower + 1] > obj->arr[lower])
            lower++;
        if (obj->arr[lower] < obj->arr[upper])
            break;
        if (obj->arr[upper] < obj->arr[lower])
        {
            tmp = obj->arr[upper];
            obj->arr[upper] = obj->arr[lower];
            obj->arr[lower] = tmp;
        }
        lower = upper;
        upper = (lower + 1) / 2 - 1;
    }
}

int pop_max_heap(HEAP *obj)
{
    int r = obj->arr[0];
    obj->arr[0] = obj->arr[--obj->size];
    int n = obj->size;
    int upper = 0;
    int lower = 2 * upper + 1;
    int tmp;
    while (lower < n)
    {
        if (lower + 1 < n && obj->arr[lower + 1] > obj->arr[lower])
            lower++;
        if (obj->arr[lower] < obj->arr[upper])
            break;
        if (obj->arr[upper] < obj->arr[lower])
        {
            tmp = obj->arr[upper];
            obj->arr[upper] = obj->arr[lower];
            obj->arr[lower] = tmp;
        }
        upper = lower;
        lower = upper * 2 + 1;
    }
    return r;
}