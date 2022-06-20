/*
 * @lc app=leetcode id=560 lang=c
 *
 * [560] Subarray Sum Equals K
 */

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -10^7 <= k <= 10^7

// @lc code=start
#define CAPACITY 10000000
int subarraySum(int *nums, int numsSize, int k)
{
    // Hash Table -> Avoid Time Limit Exceeded
    // -10^7 <= k <= 10^7
    int *hash_table = calloc(CAPACITY * 2 + 1, sizeof(int));
    int sum = 0;
    int count = 0;
    hash_table[CAPACITY] = 1;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        count += hash_table[sum - k + CAPACITY];
        ++hash_table[sum + CAPACITY];
    }
    return count;
}
// @lc code=end
