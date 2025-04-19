/*
 * @lc app=leetcode id=16 lang=c
 *
 * [16] 3Sum Closest
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int threeSumClosest(int *nums, int numsSize, int target)
{
    int min = INT_MAX;
    int r = target;
    qsort(nums, numsSize, sizeof(int), sort);
    int left, right;
    int sum, com;
    for (int i = 0; i + 2 < numsSize; i++)
    {
        left = i + 1;
        right = numsSize - 1;
        while (right - left >= 1)
        {
            sum = nums[i] + nums[left] + nums[right];
            com = abs(sum - target);
            if (com < min)
            {
                min = com;
                r = sum;
            }

            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else
                return target;
        }
    }

    return r;
}
// @lc code=end
