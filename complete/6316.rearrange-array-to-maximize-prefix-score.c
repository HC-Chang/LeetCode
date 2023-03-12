/*
 * @lc app=leetcode id=6316 lang=c
 *
 * [6316] Rearrange Array to Maximize Prefix Score
 */

// Difficulty: Medium

// You are given a 0-indexed integer array nums. You can rearrange the elements of nums to any order (including the given order).
// Let prefix be the array containing the prefix sums of nums after rearranging it.
// In other words, prefix[i] is the sum of the elements from 0 to i in nums after rearranging it.
// The score of nums is the number of positive integers in the array prefix.
// Return the maximum score you can achieve.

// Constraints:
// 1 <= nums.length <= 105
// -106 <= nums[i] <= 106

// @lc code=start
int sort(void *a, void *b) { return *(int *)b - *(int *)a; }

int maxScore(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0] > 0 ? 1 : 0;
    qsort(nums, numsSize, sizeof(int), sort);
    long long sum = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        if (sum > 0)
            count++;
        else
            break;
    }
    return count;
}

// @lc code=end