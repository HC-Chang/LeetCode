/*
 * @lc app=leetcode id=75 lang=c
 *
 * [75] Sort Colors
 */

// @lc code=start
// Solution 2: hash table

void sortColors(int* nums, int numsSize) {
    int hash[3] = {0};
    for(int i =0; i<numsSize; i++)
        ++hash[nums[i]];
    int idx = 0;
    for(int i =0; i<3; i++)
    {
        for(int j =0; j<hash[i];j++)
            nums[idx++] = i;
    }
}
// @lc code=end

// Note: sorting

// Solution 1: qsort

// int sort(const void *a, const void *b)
// {
//     return *(int *)a - *(int *)b;
// }

// void sortColors(int *nums, int numsSize)
// {
//     qsort(nums, numsSize, sizeof(int), sort);
// }