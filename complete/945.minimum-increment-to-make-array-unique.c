/*
 * @lc app=leetcode id=945 lang=c
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
#define SIZE 101001
int minIncrementForUnique(int *nums, int numsSize)
{
    int hash[SIZE] = {0};
    int cnt = 0;
    int offset = 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (!hash[nums[i]])
            ++hash[nums[i]];
        else
        {
            while (nums[i] + offset < SIZE - 1 && (hash[nums[i] + offset]) > 0)
                offset++;
            hash[nums[i] + offset] = 1;
            cnt += offset;
            offset = 1;
        }
    }

    return cnt;
}
// @lc code=end

// Note: sorting + counting