/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 */

// @lc code=start
// Solution 3: sum
int missingNumber(int *nums, int numsSize)
{
    int r = numsSize*(numsSize+1)/2;
    for(int i=0; i<numsSize; i++)
        r-=nums[i];
    return r;
}
// @lc code=end

// Solution 1:
// int missingNumber(int *nums, int numsSize)
// {
//     int hash[numsSize + 1];
//     memset(hash, 0, (numsSize + 1) * sizeof(int));
//     for (int i = 0; i < numsSize; i++)
//         ++hash[nums[i]];
//     int i;
//     for (i = 0; i <= numsSize; i++)
//     {
//         if (hash[i] == 0)
//             break;
//     }
//     return i;
// }

// Solution 2: bit manipulation
// int missingNumber(int *nums, int numsSize)
// {
//     int r = numsSize;
//     for (int i = 0; i < numsSize; i++)
//         r ^= i ^ nums[i];
//     return r;
// }