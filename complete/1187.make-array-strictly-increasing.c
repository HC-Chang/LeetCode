/*
 * @lc app=leetcode id=1187 lang=c
 *
 * [1187] Make Array Strictly Increasing
 */

// @lc code=start
const int INF = 0x3f3f3f3f;

int min(int a, int b) { return a < b ? a : b; }

int sort(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int binarySearch(int *arr, int left, int right, int val)
{
    int r = right + 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] >= val)
        {
            r = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return r;
}

int makeArrayIncreasing(int *arr1, int arr1Size, int *arr2, int arr2Size)
{
    int n = arr1Size + 2;
    int arr[n];
    memcpy(arr + 1, arr1, sizeof(int) * arr1Size);
    arr1 = arr;
    arr1[0] = -1;
    arr1[arr1Size + 1] = INF;
    qsort(arr2, arr2Size, sizeof(int), sort);
    int m = 0;
    for (int i = 0, j = 0; i < arr2Size; i++)
    {
        if (i == 0 || arr2[i] != arr2[i - 1])
            arr2[m++] = arr2[i];
    }

    int dp[n];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr1[i - 1] < arr1[i])
            dp[i] = min(dp[i], dp[i - 1]);
        int k = binarySearch(arr2, 0, m - 1, arr1[i]);
        for (int j = 1; j <= min(i - 1, k); ++j)
        {
            if (arr1[i - j - 1] < arr2[k - j])
                dp[i] = min(dp[i], dp[i - j - 1] + j);
        }
    }
    return dp[n - 1] == INF ? -1 : dp[n - 1];
}

// @lc code=end
