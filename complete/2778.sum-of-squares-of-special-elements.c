/*
 * @lc app=leetcode id=2778 lang=c
 *
 * [2778] Sum of Squares of Special Elements
 */

// @lc code=start
int sumOfSquares(int *nums, int numsSize)
{
    nums[0] *= nums[0];
    for (int i = 2; i <= numsSize; i++)
    {
        if (numsSize % i == 0)
            nums[0] += nums[i - 1] * nums[i - 1];
    }

    return nums[0];
}
// @lc code=end

// Note: enumeration