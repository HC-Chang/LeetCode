/*
 * @lc app=leetcode id=945 lang=c
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
// Solution 2:

int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int minIncrementForUnique(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);
    int cnt = 0;
    int last = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        if (nums[i] <= last)
        {
            cnt += last - nums[i] + 1;
            last++;
        }
        else
            last = nums[i];
    }
    return cnt;
}
// @lc code=end

// Note: sorting + counting

// Solution 1:

// #define SIZE 101001
// int minIncrementForUnique(int *nums, int numsSize)
// {
//     int hash[SIZE] = {0};
//     int cnt = 0;
//     int offset = 1;
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (!hash[nums[i]])
//             ++hash[nums[i]];
//         else
//         {
//             while (nums[i] + offset < SIZE - 1 && (hash[nums[i] + offset]) > 0)
//                 offset++;
//             hash[nums[i] + offset] = 1;
//             cnt += offset;
//             offset = 1;
//         }
//     }

//     return cnt;
// }