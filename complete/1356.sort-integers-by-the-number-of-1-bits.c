/*
 * @lc app=leetcode id=1356 lang=c
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Solution 2:

int count_bits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1;
        n >>= 1;
    }

    return count;
}
int sort(const void *a, const void *b)
{
    int n1 = count_bits(*(int *)a);
    int n2 = count_bits(*(int *)b);
    if (n1 == n2)
        return *(int *)a - *(int *)b;
    return n1 - n2;
}
int *sortByBits(int *arr, int arrSize, int *returnSize)
{
    *returnSize = arrSize;
    qsort(arr, arrSize, sizeof(int), sort);
    return arr;
}
// @lc code=end

// Solution 1:
// typedef struct
// {
//     int val;
//     int bit_count;
// } DATA;

// int count_bits(int n)
// {
//     int count = 0;
//     while (n > 0)
//     {
//         count += n & 1;
//         n >>= 1;
//     }
//     return count;
// }

// int sort(const void *a, const void *b)
// {
//     if (((DATA *)a)->bit_count == ((DATA *)b)->bit_count)
//         return ((DATA *)a)->val - ((DATA *)b)->val;
//     return ((DATA *)a)->bit_count - ((DATA *)b)->bit_count;
// }

// int *sortByBits(int *arr, int arrSize, int *returnSize)
// {
//     *returnSize = arrSize;
//     DATA d[arrSize];
//     for (int i = 0; i < arrSize; i++)
//     {
//         d[i].val = arr[i];
//         d[i].bit_count = count_bits(arr[i]);
//     }
//     qsort(&d, arrSize, sizeof(DATA), sort);
//     for (int i = 0; i < arrSize; i++)
//         arr[i] = d[i].val;
//     return arr;
// }