/*
 * @lc app=leetcode id=989 lang=c
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void push_arr(int val, int *arr, int *arr_size)
{
    arr[(*arr_size)++] = val;
}

void reverse_arr(int *arr, int arr_size)
{
    int tmp;
    for (int i = 0; i < arr_size / 2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[arr_size - 1 - i];
        arr[arr_size - 1 - i] = tmp;
    }
}

int *addToArrayForm(int *num, int numSize, int k, int *returnSize)
{
    int *arr = calloc(10001, sizeof(int));
    int arr_size = 0;
    int i = numSize;
    while (--i >= 0 || k > 0)
    {
        if (i >= 0)
            k += num[i];
        push_arr(k % 10, arr, &arr_size);
        k /= 10;
    }
    *returnSize = arr_size;
    arr = realloc(arr, *returnSize * sizeof(int));
    reverse_arr(arr, arr_size);
    return arr;
}

// @lc code=end
