/*
 * @lc app=leetcode id=2529 lang=c
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 */

// Difficulty:Easy

// @lc code=start
int binary_search(int *arr, int arrSize)
{
    int left = 0;
    int right = arrSize - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] >= 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int maximumCount(int *nums, int numsSize)
{
    int neg = binary_search(nums, numsSize);
    int pos = neg;
    while (pos < numsSize && nums[pos] <= 0)
        pos++;
    pos = numsSize - pos;
    return pos > neg ? pos : neg;
}
// @lc code=end