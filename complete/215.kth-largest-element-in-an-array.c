/*
 * @lc app=leetcode id=215 lang=c
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
// Solution 3: Heap (Priority Queue)
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

int findKthLargest(int *nums, int numsSize, int k)
{
    KthLargest *obj = malloc(sizeof(KthLargest));
    obj->heap = malloc(sizeof(struct Heap));
    init_heap(obj->heap, k + 1, cmp);
    obj->maxSize = k;
    int r;
    for (int i = 0; i < numsSize; i++)
        r = kthLargestAdd(obj, nums[i]);
    kthLargestFree(obj);
    return r;
}
// @lc code=end

// Solution 1: sort
// int sort(void *a, void *b) { return *(int *)b - *(int *)a; }

// int findKthLargest(int *nums, int numsSize, int k)
// {
//     qsort(nums, numsSize, sizeof(int), sort);
//     return nums[k - 1];
// }

//////////////////////////////////////////////////

// Solution 2: max heap
// static void swap(int *a, int *b)
// {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// static void heapify(int *nums, int cur, int numsSize)
// {
//     int l_chd = (cur << 1) + 1;
//     int r_chd = (cur << 1) + 2;
//     int max = cur;
//     if (l_chd < numsSize && nums[l_chd] > nums[max])
//         max = l_chd;
//     if (r_chd < numsSize && nums[r_chd] > nums[max])
//         max = r_chd;

//     if (max != cur)
//     {
//         swap(&nums[max], &nums[cur]);
//         heapify(nums, max, numsSize);
//     }
// }

// static int del_max_heap(int *nums, int numsSize)
// {
//     int r = nums[0];
//     nums[0] = nums[numsSize - 1];
//     heapify(nums, 0, numsSize);
//     return r;
// }

// static void init_heap(int *nums, int numsSize)
// {
//     for (int i = (numsSize - 1) / 2; i >= 0; i--)
//         heapify(nums, i, numsSize);
// }

// int findKthLargest(int *nums, int numsSize, int k)
// {
//     init_heap(nums, numsSize);
//     int r = 0;
//     for (int i = 0; i < k; i++)
//         r = del_max_heap(nums, numsSize--);

//     return r;
// }