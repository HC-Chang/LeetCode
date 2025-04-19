/*
 * @lc app=leetcode id=1838 lang=c
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int maxFrequency(int *nums, int numsSize, int k)
{
    int res = 0;
    long sum = 0;
    int left = 0;
    int right = 0;
    qsort(nums, numsSize, sizeof(int), sort);
    while (right < numsSize)
    {
        sum += nums[right];
        while (sum + k < (long)nums[right] * (right - left + 1))
        {
            sum -= nums[left];
            left++;
        }
        res = fmax(res, right - left + 1);
        right++;
    }
    return res;
}
// @lc code=end
