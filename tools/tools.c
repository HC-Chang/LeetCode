#define MAX(a, b) a >= b ? a : b
#define MIN(a, b) a <= b ? a : b

/**
 * @brief sum
 *
 * @param arr
 * @param size
 * @return int
 */
int sum(int *arr, int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s += arr[i];
    }

    return s;
}


int POW(int x, int y)
{
    int r = 1;
    for (int i = 0; i < y; i++)
    {
        r *= x;
    }
    return r;
}

int interger_count(int x)
{
    int count = 1;
    while (x / 10)
    {
        count++;
        x /= 10;
    }
    return count;
}

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

#pragma endregion