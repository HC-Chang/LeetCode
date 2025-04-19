/*
 * @lc app=leetcode id=950 lang=c
 *
 * [950] Reveal Cards In Increasing Order
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct
{
    int size;
    int push_idx;
    int pop_idx;
    int *arr;
} QUEUE;

QUEUE *init_queue(int size)
{
    QUEUE *obj = malloc(sizeof(QUEUE));
    obj->size = size;
    obj->push_idx = 0;
    obj->pop_idx = 0;
    obj->arr = calloc(size, sizeof(int));
    return obj;
}
void push_queue(int val, QUEUE *obj) { obj->arr[obj->push_idx++] = val; }

int top_queue(QUEUE *obj)
{
    return obj->arr[obj->pop_idx];
}

void pop_queue(QUEUE *obj) { obj->pop_idx++; }

void free_queue(QUEUE *obj)
{
    free(obj->arr);
    free(obj);
}

int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int *deckRevealedIncreasing(int *deck, int deckSize, int *returnSize)
{
    QUEUE *q = init_queue(2 * deckSize);
    qsort(deck, deckSize, sizeof(int), sort);
    for (int i = 0; i < deckSize; i++)
        push_queue(i, q);

    int *r = malloc(deckSize * sizeof(int));
    *returnSize = deckSize;
    int tmp;
    for (int i = 0; i < deckSize; i++)
    {
        tmp = top_queue(q);
        pop_queue(q);
        r[tmp] = deck[i];
        push_queue(top_queue(q), q);
        pop_queue(q);
    }
    free_queue(q);
    return r;
}
// @lc code=end

// Note: sorting + queue