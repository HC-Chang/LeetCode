/*
 * @lc app=leetcode id=502 lang=c
 *
 * [502] IPO
 */

// @lc code=start

typedef struct
{
    int capital;
    int profit;
} PROJECT;

int sort(const void *a, const void *b)
{
    if (((PROJECT *)a)->capital != ((PROJECT *)b))
        return ((PROJECT *)a)->capital - ((PROJECT *)b)->capital;
    else
        return ((PROJECT *)a)->profit - ((PROJECT *)b)->profit;
}

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void heapify(int *nums, int cur, int numsSize)
{
    int l_chd = (cur << 1) + 1;
    int r_chd = (cur << 1) + 2;
    int max = cur;
    if (l_chd < numsSize && nums[l_chd] > nums[max])
        max = l_chd;
    if (r_chd < numsSize && nums[r_chd] > nums[max])
        max = r_chd;

    if (max != cur)
    {
        swap(&nums[max], &nums[cur]);
        heapify(nums, max, numsSize);
    }
}

static int del_max_heap(int *nums, int numsSize)
{
    int r = nums[0];
    nums[0] = nums[numsSize - 1];
    heapify(nums, 0, numsSize);
    return r;
}

static void init_heap(int *nums, int numsSize)
{
    for (int i = (numsSize - 1) / 2; i >= 0; i--)
        heapify(nums, i, numsSize);
}

int findMaximizedCapital(int k, int w, int *profits, int profitsSize, int *capital, int capitalSize)
{
    int n = profitsSize;
    PROJECT *p = calloc(n, sizeof(PROJECT));

    for (int i = 0; i < n; i++)
    {
        p[i].capital = capital[i];
        p[i].profit = profits[i];
    }

    qsort(p, n, sizeof(PROJECT), sort);

    int ptr = 0;
    int heap_count = 0;
    int last_heap_count = 0;
    int *heap = calloc(n, sizeof(int));

    for (int i = 0; i < k; i++)
    {
        while (ptr < n && p[ptr].capital <= w)
            heap[heap_count++] = p[ptr++].profit;

        if (!heap_count)
            break;
        if (last_heap_count != heap_count)
            init_heap(heap, heap_count);
        w += del_max_heap(heap, heap_count--);
        last_heap_count = heap_count;
    }

    free(p);
    free(heap);
    return w;
}
// @lc code=end
