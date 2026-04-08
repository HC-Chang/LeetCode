/*
 * @lc app=leetcode id=3653 lang=c
 *
 * [3653] XOR After Range Multiplication Queries I
 */

// @lc code=start
int xorAfterQueries(int *nums, int numsSize, int **queries, int queriesSize, int *queriesColSize)
{
    static const int mod = 1e9 + 7;
    for (int i = 0; i < queriesSize; i++)
    {
        for (int j = queries[i][0]; j <= queries[i][1]; j += queries[i][2])
            nums[j] = 1LL * nums[j] * queries[i][3] % mod;
    }

    for (int i = 1; i < numsSize; i++)
        nums[i] ^= nums[i - 1];

    return nums[numsSize - 1];
}
// @lc code=end
