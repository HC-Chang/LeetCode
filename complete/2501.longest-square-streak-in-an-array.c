/*
 * @lc app=leetcode id=2501 lang=c
 *
 * [2501] Longest Square Streak in an Array
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int longestSquareStreak(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);
    int n = numsSize;
    int m = (int)sqrt(nums[n - 1]);

    int cnt = 0;
    int tmp = 0;
    int hash[nums[n - 1] + 1];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < n; i++)
        hash[nums[i]] = 1;
    long long val;
    for (int i = 0; i < n; i++)
    {
        tmp = 0;
        val = (long long)nums[i] * (long long)nums[i];
        while (val <= nums[n - 1])
        {
            if (hash[val])
            {
                if (tmp == 0)
                    tmp = 2;
                else
                    tmp++;
                hash[val] = 0;
            }
            else
                break;
            val *= val;
        }
        if (tmp > cnt)
            cnt = tmp;
    }
    return cnt == 0 ? -1 : cnt;
}
// @lc code=end

// Note: hash table + sorting + DP