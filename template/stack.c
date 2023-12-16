// Stack
// Similar Questions: 155.844

// stack api:
// - init
// - push
// - pop
// - is_empty
// - free

typedef struct
{
    int capacity;
    int index;
    char *arr_val;
} STACK;

STACK *init_stack(int n)
{
    STACK *obj = malloc(sizeof(STACK));
    obj->capacity = n;
    obj->index = 0;
    obj->arr_val = calloc(n, sizeof(char));
    return obj;
}

void push_stack(char input, STACK *obj)
{
    obj->arr_val[obj->index++] = input;
}

char pop_stack(STACK *obj)
{
    return obj->arr_val[--obj->index];
}

int is_empty_stack(STACK *obj)
{
    return obj->index == 0;
}

void free_stack(STACK *obj)
{
    free(obj->arr_val);
    free(obj);
}
