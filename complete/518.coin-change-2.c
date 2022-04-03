/*
 * @lc app=leetcode id=518 lang=c
 *
 * [518] Coin Change 2
 */

// NOTE 完全背包問題

// @lc code=start
/**
 * @brief swap
 *
 * @param x
 * @param y
 */
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

#pragma region quick_sort

/**
 * @brief quick_sort_recursive
 *
 * @param arr
 * @param start
 * @param end
 */
void quick_sort_recursive(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right)
    {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

/**
 * @brief quick_sort
 *
 * @param arr
 * @param len
 */
void quick_sort(int arr[], int len)
{
    quick_sort_recursive(arr, 0, len - 1);
}

#pragma endregion quick_sort

int change(int amount, int *coins, int coinsSize)
{
    // sort coins
    quick_sort(coins, coinsSize);

    int *dp = calloc(amount + 1, sizeof(int));

    // base case
    dp[0] = 1;

    for (int i = 0; i < coinsSize; i++)
    {
        for (int j = coins[0]; j <= amount; j++)
        {
            if (j - coins[i] >= 0)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
    }

    return dp[amount];
}
// @lc code=end
