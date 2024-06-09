/*
 * @lc app=leetcode id=974 lang=c
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
int subarraysDivByK(int *nums, int numsSize, int k)
{
    int *map = calloc(k, sizeof(int));
    map[0] = 1;

    int count = 0;
    int r = 0;
    for (int i = 0; i < numsSize; i++)
    {
        r = ((r + nums[i]) % k + k) % k;
        count += map[r];
        map[r]++;
    }
    free(map);
    return count;
}
// @lc code=end

// Note: hash table + prefix sum

// 前缀和可能是負数
// r = ((r + nums[i]) % k + k) % k;
