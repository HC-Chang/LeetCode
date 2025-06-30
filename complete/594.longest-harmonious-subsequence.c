/*
 * @lc app=leetcode id=594 lang=c
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int findLHS(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);
    int max_cnt = 0;
    int r = 0;
    for (int l = 0; l < numsSize; l++)
    {
        while (r + 1 < numsSize && nums[r + 1] - nums[l] <= 1)
            r++;
        if (nums[r] - nums[l] == 1 && r - l + 1 > max_cnt)
            max_cnt = r - l + 1;
        while (l + 1 < numsSize && nums[l + 1] == nums[l])
            l++;
    }
    return max_cnt;
}
// @lc code=end

// Note: sliding window + hash table + sorting + counting