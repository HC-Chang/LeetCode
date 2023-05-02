/*
 * @lc app=leetcode id=1822 lang=c
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
int arraySign(int *nums, int numsSize)
{
    int n_count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
            return 0;
        else if (nums[i] < 0)
            n_count++;
    }
    return n_count % 2 == 0 ? 1 : -1;
}
// @lc code=end
