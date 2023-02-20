/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */

// @lc code=start
int bin_search(int *arr, int arr_size, int target)
{
    int left = 0;
    int right = arr_size - 1;
    int middle;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (target == arr[middle])
            return middle;
        else if (target < arr[middle])
            right = middle - 1;
        else if (target > arr[middle])
            left = middle + 1;
    }
    return left;
}

int searchInsert(int *nums, int numsSize, int target)
{
    return bin_search(nums, numsSize, target);
}
// @lc code=end

// Note: Binary Search