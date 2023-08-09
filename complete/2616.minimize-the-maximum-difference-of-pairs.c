/*
 * @lc app=leetcode id=2616 lang=c
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
int countValidPairs(int *nums, int numsSize, int threshold)
{
    int index = 0, count = 0;
    while (index < numsSize - 1)
    {
        if (nums[index + 1] - nums[index] <= threshold)
        {
            count++;
            index++;
        }
        index++;
    }
    return count;
}

int sort(void *a, void *b) { return *(int *)a - *(int *)b; }

int minimizeMax(int *nums, int numsSize, int p)
{
    qsort(nums, numsSize, sizeof(int), sort);
    int left = 0, right = nums[numsSize - 1] - nums[0];
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;

        if (countValidPairs(nums, numsSize, mid) >= p)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
// @lc code=end