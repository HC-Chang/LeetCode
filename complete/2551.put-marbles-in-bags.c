/*
 * @lc app=leetcode id=2551 lang=c
 *
 * [2551]  Put Marbles in Bags
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(long long *)a - *(long long *)b; }
long long putMarbles(int *weights, int weightsSize, int k)
{
    if (weightsSize == 1)
        return 0;

    long long *arr = malloc((weightsSize - 1) * sizeof(long long));
    for (int i = 0; i < weightsSize - 1; i++)
        arr[i] = weights[i] + weights[i + 1];
    qsort(arr, weightsSize - 1, sizeof(long long), sort);

    long long r = 0;
    for (int i = 0; i < k - 1; i++)
        r += arr[weightsSize - 2 - i] - arr[i];

    free(arr);
    return r;
}
// @lc code=end