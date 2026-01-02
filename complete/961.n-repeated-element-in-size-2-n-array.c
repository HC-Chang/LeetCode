/*
 * @lc app=leetcode id=961 lang=c
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
#define ARR_SIZE (const unsigned int)(1e4 + 1)

int repeatedNTimes(int *nums, int numsSize)
{
    int hash[ARR_SIZE];
    memset(hash, 0, sizeof(hash));

    for (int i = 0; i < numsSize; i++)
    {
        if (++hash[nums[i]] >= 2)
            return nums[i];
    }
    return nums[0];
}
// @lc code=end

// Note: hash table