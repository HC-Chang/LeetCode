/*
 * @lc app=leetcode id=396 lang=c
 *
 * [396] Rotate Function
 */

// @lc code=start
int maxRotateFunction(int *nums, int numsSize)
{
    int sum = nums[0];
    int tmp = 0;
    for (int i = 1; i < numsSize; i++)
    {
        tmp += nums[i] * i;
        sum += nums[i];
    }
    int ans = INT_MIN;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        tmp += sum - numsSize * nums[i];
        ans = fmax(ans, tmp);
    }

    return ans;
}
// @lc code=end

// Note: math + DP