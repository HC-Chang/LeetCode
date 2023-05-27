// Binary Search
// Similar Questions: 704

#define TRUE 1
#define FALSE 0

// leetcode: 704
// Binary Search
// [left,right]
int bin_search(int *arr, int arr_size, int target)
{
    int left = 0;
    int right = arr_size - 1;
    int middle;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (target == arr[middle])
        {
            return TRUE;
        }
        else if (target < arr[middle])
        {
            right = middle - 1;
        }
        else if (target > arr[middle])
        {
            left = middle + 1;
        }
    }
    return FALSE;
}

// Left Side Binary Search
// [left,right)
int bin_search_left(int *arr, int arr_size, int target)
{
    int left = 0;
    int right = arr_size - 1;
    int middle;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (target == arr[middle])
        {
            right = middle - 1;
        }
        else if (target < arr[middle])
        {
            right = middle - 1;
        }   
        else if (target > arr[middle])
        {
            left = middle + 1;
        }
    }
    if (arr[left] != target || left >= arr_size)
    {
        return FALSE;
    }
    return TRUE;
}

// Right Side Binary Search
// (left,right]
int bin_search_right(int *arr, int arr_size, int target)
{
    int left = 0;
    int right = arr_size - 1;
    int middle;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (target == arr[middle])
        {
            left = middle + 1;
        }
        else if (target < arr[middle])
        {
            right = middle - 1;
        }
        else if (target > arr[middle])
        {
            left = middle + 1;
        }
    }
    if (arr[right] != target || right < 0)
    {
        return FALSE;
    }
    return TRUE;
}
