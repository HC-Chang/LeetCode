/*
 * @lc app=leetcode id=1508 lang=c
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int rangeSum(int *nums, int numsSize, int n, int left, int right)
{
    int nn = n * (n + 1) / 2;
    int arr[nn];
    int idx_arr = 0;

    int tmp;
    for (int i = 0; i < numsSize; i++)
    {
        tmp = 0;
        for (int j = i; j < numsSize; j++)
        {
            tmp += nums[j];
            arr[idx_arr++] = tmp;
        }
    }
    qsort(&arr, nn, sizeof(int), sort);

    long long ans = 0;
    for (int i = left - 1; i < right; i++)
        ans += arr[i];
    ans = ans % (1000000007);
    return (int)ans;
}
// @lc code=end

// Note: sorting