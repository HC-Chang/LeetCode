/*
 * @lc app=leetcode id=901 lang=c
 *
 * [901] Online Stock Span
 */

// @lc code=start
typedef struct Node
{
    int first;
    int second;
    struct Node *next;
} Node;

typedef struct
{
    Node *stack;
    int idx;
} StockSpanner;

Node *nodeCreate(int first, int second)
{
    Node *obj = (Node *)malloc(sizeof(Node));
    obj->first = first;
    obj->second = second;
    obj->next = NULL;
    return obj;
}

StockSpanner *stockSpannerCreate()
{
    StockSpanner *obj = malloc(sizeof(StockSpanner));
    obj->idx = -1;
    obj->stack = nodeCreate(-1, INT_MAX);
    return obj;
}

int stockSpannerNext(StockSpanner *obj, int price)
{
    obj->idx++;
    while (price >= obj->stack->second)
    {
        Node *p = obj->stack;
        obj->stack = obj->stack->next;
        free(p);
    }
    int ret = obj->idx - obj->stack->first;
    Node *p = nodeCreate(obj->idx, price);
    p->next = obj->stack;
    obj->stack = p;
    return ret;
}

void stockSpannerFree(StockSpanner *obj)
{
    for (Node *p = obj->stack; p;)
    {
        Node *node = p;
        p = p->next;
        free(node);
    }
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);

 * stockSpannerFree(obj);
*/
// @lc code=end

// Official Solution
// Note: Monotonic Stack