/*
 * @lc app=leetcode id=1979 lang=c
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start
int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int findGCD(int *nums, int numsSize)
{
    int min_val = nums[0];
    int max_val = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] < min_val)
            min_val = nums[i];
        else if (nums[i] > max_val)
            max_val = nums[i];
    }

    return gcd(min_val, max_val);
}
// @lc code=end

// Note: math(GCD)