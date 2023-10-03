/*
 * @lc app=leetcode id=1512 lang=c
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
int numIdenticalPairs(int *nums, int numsSize)
{
    int hash[100] = {0};
    for (int i = 0; i < numsSize; i++)
        ++hash[nums[i] - 1];
    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        if (hash[i] > 1)
            cnt += hash[i] * (hash[i] - 1) / 2;
    }

    return cnt;
}
// @lc code=end

// Note: hash