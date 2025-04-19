/*
 * @lc app=leetcode id=1913 lang=c
 *
 * [1913] Maximum Product Difference Between Two Pairs
 */

// @lc code=start
// Solution 2:
int maxProductDifference(int *nums, int numsSize)
{
    int min_arr[2] = {nums[0], nums[1]};
    int max_arr[2] = {nums[0], nums[1]};
    int *min = min_arr[0] > min_arr[1] ? &min_arr[0] : &min_arr[1];
    int *max = max_arr[0] < max_arr[1] ? &max_arr[0] : &max_arr[1];

    for (int i = 2; i < numsSize; i++)
    {
        if (nums[i] < *min)
        {
            *min = nums[i];
            min = min_arr[0] > min_arr[1] ? &min_arr[0] : &min_arr[1];
        }
        if (nums[i] > *max)
        {
            *max = nums[i];
            max = max_arr[0] < max_arr[1] ? &max_arr[0] : &max_arr[1];
        }
    }

    return max_arr[0] * max_arr[1] - min_arr[0] * min_arr[1];
}
// @lc code=end

// Note: sorting

// Solution 1: 

// int sort(const void *a, const void *b){return *(int*)a - *(int*)b;}
// int maxProductDifference(int* nums, int numsSize){
//     qsort(nums, numsSize, sizeof(int), sort);
//     return nums[numsSize-1]*nums[numsSize-2] - nums[0]*nums[1];
// }