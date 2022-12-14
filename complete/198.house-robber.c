/*
 * @lc app=leetcode id=198 lang=c
 *
 * [198] House Robber
 */

// @lc code=start
#define maxx(a,b) a>b?a:b

int rob(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
        return maxx(nums[0], nums[1]);

    int even = 0;
    int odd = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i % 2 == 0)
            even = maxx(even + nums[i], odd);
        else
            odd = maxx(even, odd + nums[i]);
    }
    return maxx(even, odd);
}
// @lc code=end
