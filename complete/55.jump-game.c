/*
 * @lc app=leetcode id=55 lang=c
 *
 * [55] Jump Game
 */

// @lc code=start
int max(int a, int b)
{
    return a > b ? a : b;
}

bool canJump(int *nums, int numsSize)
{
    int far_step = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        far_step = max(far_step, nums[i] + i);
        if (far_step <= i)
        {
            return false;
        }
    }

    return far_step >= numsSize - 1;
}
// @lc code=end
