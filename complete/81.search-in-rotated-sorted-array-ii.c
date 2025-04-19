/*
 * @lc app=leetcode id=81 lang=c
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
// Solution 2:
bool search(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return true;

        if ((nums[left] == nums[mid]) && (nums[right] == nums[mid]))
        {
            left++;
            right--;
        }
        else if (nums[left] <= nums[mid])
        {
            if ((nums[left] <= target) && (nums[mid] > target))
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if ((nums[mid] < target) && (nums[right] >= target))
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}
// @lc code=end

// Note: binary search

// Solution 1:
// int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
// bool search(int *nums, int numsSize, int target)
// {
//     qsort(nums, numsSize, sizeof(int), sort);
//     int left = 0;
//     int right = numsSize - 1;
//     int mid;
//     while (left <= right)
//     {
//         mid = left + (right - left) / 2;
//         if (nums[mid] == target)
//             return true;
//         else if (nums[mid] > target)
//             right = mid - 1;
//         else if (nums[mid] < target)
//             left = mid + 1;
//     }
//     return false;
// }