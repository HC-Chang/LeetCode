/*
 * @lc app=leetcode id=33 lang=c
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
// Solution 2:
// 檢視中間與右邊，判斷旋轉狀況
int search(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int middle;

    while (left <= right)
    {
        middle = left + (right - left) / 2;

        if (nums[middle] == target)
            return middle;

        if (nums[middle] > nums[right])
        {
            if (target < nums[middle] && target >= nums[left])
                right = middle - 1;
            else
                left = middle + 1;
        }
        else
        {
            if (target > nums[middle] && target <= nums[right])
                left = middle + 1;
            else
                right = middle - 1;
        }
    }

    return -1;
}
// @lc code=end

// Solution 1:
// int search(int *nums, int numsSize, int target)
// {
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] == target)
//         {
//             return i;
//         }
//     }
//     return -1;
// }