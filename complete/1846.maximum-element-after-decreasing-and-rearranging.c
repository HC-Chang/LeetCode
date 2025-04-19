/*
 * @lc app=leetcode id=1846 lang=c
 *
 * [1846] Maximum Element After Decreasing and Rearranging
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int maximumElementAfterDecrementingAndRearranging(int *arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), sort);
    arr[0] = 1;
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] - arr[i - 1] > 1)
            arr[i] = arr[i - 1] + 1;
    }
    return arr[arrSize - 1];
}
// @lc code=end
