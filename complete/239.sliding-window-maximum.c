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

int top_monotonic_queue(MonotonicQueue *obj)
{
    return obj->arr[obj->head];
}

void pop_monotonic_queue(MonotonicQueue *obj)
{
    obj->head++;
}

void free_monotonic_queue(MonotonicQueue *obj)
{
    free(obj->arr);
    free(obj);
}

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
    int *ans = malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = 0;

    MonotonicQueue *q = init_monotonic_queue(numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        push_monotonic_queue(nums[i], q);

        if (i >= k - 1)
        {
            ans[(*returnSize)++] = top_monotonic_queue(q);

            if (top_monotonic_queue(q) == nums[i - k + 1])
                pop_monotonic_queue(q);
        }
    }

    free_monotonic_queue(q);
    return ans;
}
// @lc code=end

// Note: Heap . Monotonic Queue