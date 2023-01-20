/*
 * @lc app=leetcode id=225 lang=c
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start

typedef struct
{
    int count;
    int arr[100];
} QUEUE;

void push_queue(int x, QUEUE *q)
{
    q->arr[q->count++] = x;
}

void pop_queue(QUEUE *q)
{
    q->count--;
}
int top_queue(QUEUE *q)
{
    return q->arr[q->count - 1];
}

bool is_empty_queue(QUEUE *q)
{
    return q->count == 0;
}

typedef struct
{
    QUEUE *q;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *my_stack = calloc(1, sizeof(MyStack));
    my_stack->q = calloc(1, sizeof(QUEUE));
    my_stack->q->count = 0;

    return my_stack;
}

void myStackPush(MyStack *obj, int x)
{
    int sz = obj->q->count;
    push_queue(x, obj->q);
    while (sz--)
    {
        push_queue(top_queue(obj->q), obj->q);
        pop_queue(obj->q);
    }
}

int myStackTop(MyStack *obj)
{
    return top_queue(obj->q);
}

int myStackPop(MyStack *obj)
{
    int result = myStackTop(obj);
    pop_queue(obj->q);
    return result;
}

bool myStackEmpty(MyStack *obj)
{
    return is_empty_queue(obj->q);
}

void myStackFree(MyStack *obj)
{
    free(obj->q);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
// @lc code=end

// queue api:
// - push
// - pop
// - top
// - is_empty
