/*
 * @lc app=leetcode id=232 lang=c
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start

struct linkedList
{
    int data;
    struct linkedList *next;
};

typedef struct linkedList LIST;

typedef struct
{
    LIST *head;
} STACK;

STACK *stackCreate()
{
    STACK *obj = calloc(1, sizeof(STACK));
    return obj;
}

void push_stack(STACK *obj, int val)
{
    LIST *node = calloc(1, sizeof(LIST));
    node->data = val;

    if (!obj->head)
        obj->head = node;
    else
    {
        node->next = obj->head;
        obj->head = node;
    }
}

void pop_stack(STACK *obj)
{
    if (obj->head == NULL)
        return;

    if (!obj->head->next)
    {
        free(obj->head);
        obj->head = NULL;
    }
    else
    {
        LIST *tmp = obj->head->next;
        free(obj->head);
        obj->head = tmp;
    }
}

bool is_empty_stack(STACK *obj)
{
    return (obj->head == NULL ? true : false);
}

int top_stack(STACK *obj)
{
    if (obj->head != NULL)
    {
        return obj->head->data;
    }
    return (-1);
}

void free_stack(STACK *obj)
{
    while (obj->head != NULL)
    {
        LIST *tmp = obj->head->next;
        free(obj->head);
        obj->head = tmp;
    }
    free(obj);
}

enum
{
    MAIN_S = 0,
    BACK_S = 1,
};

typedef struct
{
    STACK *s[2];
} MyQueue;

MyQueue *myQueueCreate()
{
    STACK *s0 = stackCreate();
    STACK *s1 = stackCreate();

    MyQueue *q = malloc(sizeof(MyQueue));
    q->s[MAIN_S] = s0;
    q->s[BACK_S] = s1;

    return q;
}

void myQueuePush(MyQueue *obj, int x)
{
    push_stack(obj->s[MAIN_S], x);
}

void myQueueMoveStack(MyQueue *obj)
{
    while (!is_empty_stack(obj->s[MAIN_S]))
    {
        int tmp = top_stack(obj->s[MAIN_S]);
        pop_stack(obj->s[MAIN_S]);
        push_stack(obj->s[BACK_S], tmp);
    }
}

int myQueuePop(MyQueue *obj)
{
    int result = -1;
    if (myQueueEmpty(obj))
        return result;

    if (is_empty_stack(obj->s[BACK_S]))
        myQueueMoveStack(obj);

    result = top_stack(obj->s[BACK_S]);
    pop_stack(obj->s[BACK_S]);
    if (is_empty_stack(obj->s[BACK_S]))
        myQueueMoveStack(obj);
    return result;
}

int myQueuePeek(MyQueue *obj)
{
    if (myQueueEmpty(obj))
        return -1;
    else
    {
        if (is_empty_stack(obj->s[BACK_S]))
            myQueueMoveStack(obj);
        return top_stack(obj->s[BACK_S]);
    }
}

int myQueueEmpty(MyQueue *obj)
{
    if ((is_empty_stack(obj->s[MAIN_S])) && (is_empty_stack(obj->s[BACK_S])))
        return true;
    return false;
}

void myQueueFree(MyQueue *obj)
{
    free_stack(obj->s[MAIN_S]);
    free_stack(obj->s[BACK_S]);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
// @lc code=end

// stack api:
// - push
// - pop
// - top
// - is_empty
// - free (optional)


// Note: design

// Solution 1:
// typedef struct {
//     int arr[100];
//     int index;
// }STACK;

// STACK *init_stack(void)
// {
//     STACK *obj = calloc(1, sizeof(STACK));
//     return obj;
// }
// void push_stack(int val, STACK *obj)
// {
//     obj->arr[obj->index++] = val;
// }

// int pop_stack(STACK *obj)
// {
//     if(obj->index == 0)
//         return -1;
//     return obj->arr[--obj->index];
// }

// int top_stack(STACK *obj)
// {
//     if(obj->index == 0)
//         return -1;
//     return obj->arr[obj->index-1];
// }

// bool is_empty_stack(STACK *obj)
// {
//     return obj->index <= 0;
// }

// typedef struct {
//     STACK *s1;
//     STACK *s2;
// } MyQueue;


// MyQueue* myQueueCreate() {
//     MyQueue *obj = malloc(sizeof(MyQueue));
//     obj->s1 = init_stack();
//     obj->s2 = init_stack();
//     return obj;
// }

// void myQueuePush(MyQueue* obj, int x) {
//     push_stack(x, obj->s1);
// }

// bool myQueueEmpty(MyQueue* obj) {
//     if (is_empty_stack(obj->s1) && is_empty_stack(obj->s2))
// 		return true;
// 	return false;
// }

// void transfer_stack(STACK *obj1, STACK *obj2)
// {
//     while(!is_empty_stack(obj1))
//         push_stack( pop_stack(obj1), obj2);
// }

// int myQueuePop(MyQueue* obj) {
//     if(myQueueEmpty(obj))
//         return -1;
//     if(is_empty_stack(obj->s2))
//         transfer_stack(obj->s1, obj->s2);
//     int res = pop_stack(obj->s2);
//     if(is_empty_stack(obj->s2))
//         transfer_stack(obj->s1, obj->s2);
//     return res;
// }

// int myQueuePeek(MyQueue* obj) {
//     if(myQueueEmpty(obj))
//         return -1;
//     if(is_empty_stack(obj->s2))
//         transfer_stack(obj->s1, obj->s2);
//     return top_stack(obj->s2);
// }

// void myQueueFree(MyQueue* obj) {
//     free(obj->s1);
//     free(obj->s2);
//     free(obj);
// }
