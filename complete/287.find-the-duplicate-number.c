/*
 * @lc app=leetcode id=287 lang=c
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
// Solution 2: two pointers

int findDuplicate(int *nums, int numsSize)
{
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    slow = 0;
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
// @lc code=end

// Note: hash table / two pointers

// Solution 1: hash table

// int findDuplicate(int *nums, int numsSize)
// {
//     int hash[numsSize];
//     memset(hash, 0, numsSize * sizeof(int));
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (hash[nums[i]]++ >= 1)
//             return nums[i];
//     }
//     return nums[numsSize - 1];
// }