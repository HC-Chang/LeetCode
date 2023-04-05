/*
 * @lc app=leetcode id=2439 lang=c
 *
 * [2439] Minimize Maximum of Array
 */

// @lc code=start
int max(int a, int b) { return a > b ? a : b; }
int minimizeArrayValue(int *nums, int numsSize)
{
    if (numsSize == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];

    long long sum = 0;
    int r = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        if (r < nums[i])
            r = max(r, (sum + i) / (i + 1));
    }
    return r;
}

// @lc code=end
