/*
 * @lc app=leetcode id=45 lang=c
 *
 * [45] Jump Game II
 */

// @lc code=start
int max(a, b) { return a > b ? a : b; }
int jump(int *nums, int numsSize)
{
    int last = 0, next = 0;
    int step = 0;
    for (int i = 0; i < numsSize && last < numsSize - 1; i++)
    {
        if (i > last)
        {
            step++;
            last = next;
        }
        next = max(next, i + nums[i]);
    }
    return step;
}
// @lc code=end
