/*
 * @lc app=leetcode id=1679 lang=c
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int maxOperations(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), sort);
    int count = 0;
    int left = 0, right = numsSize - 1;
    while (left < right)
    {
        if (nums[left] + nums[right] == k)
        {
            count++;
            left++;
            right--;
        }
        else if (nums[left] + nums[right] < k)
            left++;
        else if (nums[left] + nums[right] > k)
            right--;
    }
    return count;
}
// @lc code=end
