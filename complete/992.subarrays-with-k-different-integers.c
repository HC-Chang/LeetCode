/*
 * @lc app=leetcode id=992 lang=c
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
int helper(int *nums, int numsSize, int k)
{
    int res = 0, left = 0;
    int hash[numsSize + 1];
    memset(hash, 0, sizeof(hash));

    int cnt = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (++hash[nums[i]] == 1)
            ++cnt;
        while (cnt > k)
        {
            if (--hash[nums[left]] == 0)
                --cnt;
            ++left;
        }
        res += i - left + 1;
    }
    return res;
}

int subarraysWithKDistinct(int *nums, int numsSize, int k)
{
    return helper(nums, numsSize, k) - helper(nums, numsSize, k - 1);
}
// @lc code=end

// Note: hash table + sliding window