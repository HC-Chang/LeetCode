/*
 * @lc app=leetcode id=2870 lang=c
 *
 * [2870] Minimum Number of Operations to Make Array Empty
 */

// @lc code=start
int minOperations(int *nums, int numsSize)
{
    int hash[1000001] = {0};
    for (int i = 0; i < numsSize; i++)
        ++hash[nums[i]];
    int op = 0;
    int tmp;
    for (int i = 0; i < 1000001; i++)
    {
        if (hash[i] == 1)
            return -1;
        else
        {
            op += hash[i] / 3;
            if (hash[i] % 3 != 0)
                op++;
        }
    }
    return op;
}
// @lc code=end

// Note: hash table