/*
 * @lc app=leetcode id=523 lang=c
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
bool checkSubarraySum(int *nums, int numsSize, int k)
{
    if (numsSize < 2)
        return false;
    char *hash = calloc(k, sizeof(char));
    int sum = nums[0] % k;
    hash[sum] = 0;
    int tmp;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] % k == 0 && nums[i - 1] % k == 0 ||
            (nums[i] + nums[i - 1]) % k == 0)
        {
            free(hash);
            return true;
        }
        if (nums[i] % k == 0)
            continue;
        sum += nums[i];
        tmp = sum % k;
        if (!tmp)
        {
            free(hash);
            return true;
        }
        if (hash[tmp] != 0 && hash[tmp] != i)
        {
            free(hash);
            return true;
        }
        hash[tmp] = i;
    }

    free(hash);
    return false;
}
// @lc code=end

// Note: prefix sum + hash