/*
 * @lc app=leetcode id=3487 lang=c
 *
 * [3487] Maximum Unique Subarray Sum After Deletion
 */

// @lc code=start
int maxSum(int *nums, int numsSize)
{
    int hash[201] = {0};
    int sum = nums[0];
    hash[nums[0] + 100]++;
    for (int i = 1; i < numsSize; i++)
    {
        if (hash[nums[i] + 100]++ == 0)
            sum = fmax(fmax(sum, sum + nums[i]), nums[i]);
    }

    return sum;
}
// @lc code=end

// Note: hash table + greedy
