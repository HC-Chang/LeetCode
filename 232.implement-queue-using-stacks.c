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

void stackPush(STACK *obj, int val)
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

void stackPop(STACK *obj)
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

bool stackIsEmpty(STACK *obj)
{
    return (obj->head == NULL ? true : false);
}

int stackTop(STACK *obj)
{
    if (obj->head != NULL)
    {
        return obj->head->data;
    }
    return (-1);
}

void stackFree(STACK *obj)
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
    stackPush(obj->s[MAIN_S], x);
}

void myQueueMoveStack(MyQueue *obj)
{
    while (!stackIsEmpty(obj->s[MAIN_S]))
    {
        int tmp = stackTop(obj->s[MAIN_S]);
        stackPop(obj->s[MAIN_S]);
        stackPush(obj->s[BACK_S], tmp);
    }
}

int myQueuePop(MyQueue *obj)
{
    int result = -1;
    if (myQueueEmpty(obj))
        return result;

    if (stackIsEmpty(obj->s[BACK_S]))
        myQueueMoveStack(obj);

    result = stackTop(obj->s[BACK_S]);
    stackPop(obj->s[BACK_S]);
    if (stackIsEmpty(obj->s[BACK_S]))
        myQueueMoveStack(obj);
    return result;
}

int myQueuePeek(MyQueue *obj)
{
    if (myQueueEmpty(obj))
        return -1;
    else
    {
        if (stackIsEmpty(obj->s[BACK_S]))
            myQueueMoveStack(obj);
        return stackTop(obj->s[BACK_S]);
    }
}

int myQueueEmpty(MyQueue *obj)
{
    if ((stackIsEmpty(obj->s[MAIN_S])) && (stackIsEmpty(obj->s[BACK_S])))
        return true;
    return false;
}

void myQueueFree(MyQueue *obj)
{
    stackFree(obj->s[MAIN_S]);
    stackFree(obj->s[BACK_S]);
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
