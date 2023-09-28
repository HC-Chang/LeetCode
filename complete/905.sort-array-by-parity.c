/*
 * @lc app=leetcode id=905 lang=c
 *
 * [905] Sort Array By Parity
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Solution 3:
int sort(void *a, void *b) { return *(int *)a % 2 == 1; }
int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    qsort(nums, numsSize, sizeof(int), sort);
    return nums;
}
// @lc code=end

// Solution 1:
// int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
// {
//     *returnSize = numsSize;
//     int *r_array = calloc(numsSize ,sizeof(int));
//     int left = 0;
//     int right = numsSize - 1;
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] % 2 == 0)
//         {
//             *(r_array + left) = nums[i];
//             left++;
//         }
//         else
//         {
//             *(r_array + right) = nums[i];
//             right--;
//         }
//     }

//     return r_array;
// }

// Solution 2:
// void swap(int l, int r, int *nums)
// {
//     int tmp = nums[l];
//     nums[l] = nums[r];
//     nums[r] = tmp;
// }

// int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
// {
//     *returnSize = numsSize;
//     int left = 0;
//     int right = numsSize - 1;
//     while (left < right)
//     {
//         while (nums[left] % 2 == 0 && left < right)
//             left++;
//         while (nums[right] % 2 == 1 && left < right)
//             right--;

//         swap(left, right, nums);
//         left++;
//     }
//     return nums;
// }

// Note: two pointer + sort