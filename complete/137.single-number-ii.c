/*
 * @lc app=leetcode id=137 lang=c
 *
 * [137] Single Number II
 */

// @lc code=start
// Solution 2:
int singleNumber(int *nums, int numsSize)
{
    int n1 = 0, n2 = 0;
    for (int i = 0; i < numsSize; i++)
    {
        n1 = (n1 ^ nums[i]) & (~n2);
        n2 = (n2 ^ nums[i]) & (~n1);
    }
    return n1;
}
// @lc code=end

// Solution 1:

// int sort(void *a, void *b) { return *(int *)a > *(int *)b; }
// int singleNumber(int *nums, int numsSize)
// {
//     qsort(nums, numsSize, sizeof(int), sort);
//     for (int i = 0; i + 2 < numsSize; i += 3)
//     {
//         if (nums[i] == nums[i + 2])
//             continue;
//         else if (nums[i] == nums[i + 1])
//             return nums[i + 2];
//         else
//             return nums[i];
//     }

//     return nums[numsSize - 1];
// }