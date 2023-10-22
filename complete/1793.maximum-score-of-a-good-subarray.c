/*
 * @lc app=leetcode id=1793 lang=c
 *
 * [1793] Maximum Score of a Good Subarray
 */

// @lc code=start
int maximumScore(int *nums, int numsSize, int k)
{
    int min = nums[k];
    int ans = min;
    int i = k;
    int j = k;
    while (i > 0 || j < numsSize - 1)
    {
        if (i == 0 || (j + 1 < numsSize && nums[i - 1] <= nums[j + 1]))
        {
            j++;
            min = fmin(min, nums[j]);
            ans = fmax(ans, min * (j - i + 1));
        }
        else
        {
            i--;
            min = fmin(min, nums[i]);
            ans = fmax(ans, min * (j - i + 1));
        }
    }
    return ans;
}
// @lc code=end
