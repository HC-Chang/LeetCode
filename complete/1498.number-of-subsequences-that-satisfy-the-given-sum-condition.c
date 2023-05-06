/*
 * @lc app=leetcode id=1498 lang=c
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int numSubseq(int *nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), sort);
    int MOD = 1e9 + 7;
    int *pow = calloc(numsSize, sizeof(int));
    pow[0] = 1;
    for (int i = 1; i < numsSize; i++)
        pow[i] = pow[i - 1] * 2 % MOD;

    int count = 0;
    for (int i = 0, j = numsSize - 1; i < numsSize; i++)
    {
        while (nums[i] + nums[j] > target && j >= i && j > 0)
            j--;
        if (nums[i] + nums[j] <= target && j >= i && j > 0)
            count = (count + pow[j - i]) % MOD;
    }
    free(pow);
    return count;
}
// @lc code=end
