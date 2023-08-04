// Queue
// Similar Questions: 225

// queue api:
// - init
// - push
// - top
// - pop
// - size
// - is_empty
// - free

typedef struct
{
    int capacity;
    int push_index;
    int pop_index;
    int *arr_val;
} QUEUE;

QUEUE *init_queue(int n)
{
    QUEUE *obj = calloc(1, sizeof(QUEUE));
    obj->capacity = n;
    obj->arr_val = calloc(n, sizeof(int));
    return obj;
}

void push_queue(int input, QUEUE *obj)
{
    obj->arr_val[obj->push_index++] = input;
}

int top_queue(QUEUE *obj)
{
    return obj->arr_val[obj->pop_index];
}

void pop_queue(QUEUE *obj)
{
    obj->pop_index++;
}

int size_queue(QUEUE *obj)
{
    return obj->push_index - obj->pop_index;
}

int is_empty_queue(QUEUE *obj)
{
    return (obj->push_index - obj->pop_index) == 0;
}

void free_queue(QUEUE *obj)
{
    free(obj->arr_val);
    free(obj);
}
