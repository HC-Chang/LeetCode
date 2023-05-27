/*
 * @lc app=leetcode id=703 lang=c
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
struct Heap
{
    int *heap;
    int heapSize;
    bool (*cmp)(int, int);
};

void init_heap(struct Heap *obj, int n, bool (*cmp)(int, int))
{
    obj->heap = malloc(sizeof(int) * (n + 1));
    obj->heapSize = 0;
    obj->cmp = cmp;
}

bool cmp(int a, int b)
{
    return a > b;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b, *b = tmp;
}

void push_heap(struct Heap *obj, int x)
{
    int p = ++(obj->heapSize), q = p >> 1;
    obj->heap[p] = x;
    while (q)
    {
        if (!obj->cmp(obj->heap[q], obj->heap[p]))
            break;
        swap(&(obj->heap[q]), &(obj->heap[p]));
        p = q, q = p >> 1;
    }
}

void pop_heap(struct Heap *obj)
{
    swap(&(obj->heap[1]), &(obj->heap[(obj->heapSize)--]));
    int p = 1, q = p << 1;
    while (q <= obj->heapSize)
    {
        if (q + 1 <= obj->heapSize)
        {
            if (obj->cmp(obj->heap[q], obj->heap[q + 1]))
                q++;
        }
        if (!obj->cmp(obj->heap[p], obj->heap[q]))
            break;
        swap(&(obj->heap[q]), &(obj->heap[p]));
        p = q, q = p << 1;
    }
}

int top_heap(struct Heap *obj)
{
    return obj->heap[1];
}

typedef struct
{
    struct Heap *heap;
    int maxSize;
} KthLargest;

KthLargest *kthLargestCreate(int k, int *nums, int numsSize)
{
    KthLargest *ret = malloc(sizeof(KthLargest));
    ret->heap = malloc(sizeof(struct Heap));
    init_heap(ret->heap, k + 1, cmp);
    ret->maxSize = k;
    for (int i = 0; i < numsSize; i++)
        kthLargestAdd(ret, nums[i]);
    return ret;
}

int kthLargestAdd(KthLargest *obj, int val)
{
    push_heap(obj->heap, val);
    if (obj->heap->heapSize > obj->maxSize)
        pop_heap(obj->heap);
    return top_heap(obj->heap);
}

void kthLargestFree(KthLargest *obj)
{
    free(obj->heap->heap);
    free(obj->heap);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/
// @lc code=end

// Official Solution