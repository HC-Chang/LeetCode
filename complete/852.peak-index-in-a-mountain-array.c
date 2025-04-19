/*
 * @lc app=leetcode id=852 lang=c
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
// Solution 2: binary search
int peakIndexInMountainArray(int *arr, int arrSize)
{
    int left = 0;
    int right = arrSize - 1;
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }

    mid = left + (right - left) / 2;
    return mid;
}
// @lc code=end

// Solution 1:
// typedef struct
// {
//     int index;
//     int val;
// } DATA;

// int sort(const void *a, const void *b) { return ((DATA *)b)->val - ((DATA *)a)->val; }

// int peakIndexInMountainArray(int *arr, int arrSize)
// {
//     DATA *d = malloc(arrSize * sizeof(DATA));
//     for (int i = 0; i < arrSize; i++)
//     {
//         d[i].index = i;
//         d[i].val = arr[i];
//     }
//     qsort(d, arrSize, sizeof(d), sort);
//     int r = d[0].index;
//     free(d);
//     return r;
// }