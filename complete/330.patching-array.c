/*
 * @lc app=leetcode id=330 lang=c
 *
 * [330] Patching Array
 */

// @lc code=start
int minPatches(int *nums, int numsSize, int n)
{
    long long miss = 1;
    int cnt = 0;
    int i = 0;

    while (miss <= n)
    {
        if (i < numsSize && nums[i] <= miss)
            miss += nums[i++];
        else
        {
            miss += miss;
            cnt++;
        }
    }

    return cnt;
}
// @lc code=end
