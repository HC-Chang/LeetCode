/*
 * @lc app=leetcode id=1502 lang=c
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
bool canMakeArithmeticProgression(int *arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), sort);
    int dif = arr[1] - arr[0];
    for (int i = 1; i < arrSize - 1; i++)
    {
        if ((arr[i + 1] - arr[i]) != dif)
            return false;
    }
    return true;
}
// @lc code=end
