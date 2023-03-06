/*
 * @lc app=leetcode id=1539 lang=c
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
int findKthPositive(int *arr, int arrSize, int k)
{
    // Solution 2: binary search

    int left = 0;
    int right = arrSize - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] - (mid + 1) < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left + k;
}
// @lc code=end

// Solution 1:
int findKthPositive(int *arr, int arrSize, int k)
{
    if (arr[arrSize - 1] == arrSize)
        return arrSize + k;
    int index = 0;
    for (int i = 1; i < arr[arrSize - 1] + k + 1; i++)
    {
        if (index >= arrSize)
        {
            index = i;
            break;
        }
        if (arr[index] == i)
            index++;
        else
            k--;
        if (k == 0)
            return i;
    }
    return index + k - 1;
}
