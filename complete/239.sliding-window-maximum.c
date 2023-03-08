/*
 * @lc app=leetcode id=239 lang=c
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int capacity;
    int *arr;
    int head;
    int tail;
} MonotonicQueue;

MonotonicQueue *init_monotonic_queue(int capacity)
{
    MonotonicQueue *Q = malloc(sizeof(MonotonicQueue));
    Q->capacity = capacity;
    Q->arr = malloc(capacity * sizeof(int));
    Q->head = 0;
    Q->tail = -1;
    return Q;
}

int is_monotonic_queue_empty(MonotonicQueue *Q)
{
    return Q->tail < Q->head;
}

void push_back(MonotonicQueue *Q, int value)
{
    while (!is_monotonic_queue_empty(Q) && value > Q->arr[Q->tail])
    {
        Q->tail--;
    }
    Q->tail++;
    Q->arr[Q->tail] = value;
}

int get_front(MonotonicQueue *Q)
{
    return Q->arr[Q->head];
}

void pop_front(MonotonicQueue *Q)
{
    Q->head++;
}

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = 0;

    MonotonicQueue *Q = init_monotonic_queue(numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        push_back(Q, nums[i]);

        if (i >= k - 1)
        {
            ans[(*returnSize)++] = get_front(Q);

            if (get_front(Q) == nums[i - k + 1])
            {
                pop_front(Q);
            }
        }
    }

    return ans;
}
// @lc code=end
