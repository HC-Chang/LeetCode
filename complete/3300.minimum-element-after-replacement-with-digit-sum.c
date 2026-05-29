/*
 * @lc app=leetcode id=3300 lang=c
 *
 * [3300] Minimum Element After Replacement With Digit Sum
 */

// @lc code=start
int sum_val(int n)
{
    int val = 0;
    while (n)
    {
        val += n % 10;
        n /= 10;
    }
    return val;
}

int minElement(int *nums, int numsSize)
{
    int min_val = INT_MAX;
    for (int i = 0; i < numsSize; i++)
        min_val = fmin(min_val, sum_val(nums[i]));
    return min_val;
}
// @lc code=end
