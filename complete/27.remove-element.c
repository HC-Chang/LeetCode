/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start

// Solution 2: two pointer
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int removeElement(int *nums, int numsSize, int val)
{
    int index = 0;
    int n = numsSize;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != val)
        {
            swap(nums + i, nums + index);
            index++;
        }
    }
    return index;
}
// @lc code=end

// Solution 1: sort
// int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
// int removeElement(int *nums, int numsSize, int val)
// {
//     int r = numsSize;
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] == val)
//         {
//             r--;
//             nums[i] = INT_MAX;
//         }
//     }
//     qsort(nums, numsSize, sizeof(int), sort);
//     return r;
// }