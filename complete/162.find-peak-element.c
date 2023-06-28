/*
 * @lc app=leetcode id=162 lang=c
 *
 * [162] Find Peak Element
 */

// @lc code=start
// Solution 2: Binary Search
int binary_search(int *nums, int left, int right)
{
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int findPeakElement(int *nums, int numsSize)
{
    return binary_search(nums, 0, numsSize - 1);
}
// @lc code=end

// Solution 1:
// int findPeakElement(int* nums, int numsSize){
//     int max = nums[0], max_index = 0;
//     for(int i =1; i<numsSize; i++)
//     {
//         if(nums[i] >max)
//         {
//             max = nums[i];
//             max_index = i;
//         }
//     }
//     return max_index;
// }