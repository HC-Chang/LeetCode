/*
 * @lc app=leetcode id=1979 lang=c
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int gcd(int a, int b)
{
    if (a % b)
        return gcd(b, a % b);
    else
        return b;
}

int findGCD(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);
    return gcd(nums[0], nums[numsSize - 1]);
}
// @lc code=end

// Note: GCD