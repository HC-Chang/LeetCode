/*
 * @lc app=leetcode id=215 lang=c
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start

// Solution 2: max heap

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

int findKthLargest(int *nums, int numsSize, int k)
{
    init_heap(nums, numsSize);
    int r = 0;
    for (int i = 0; i < k; i++)
        r = del_max_heap(nums, numsSize--);

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