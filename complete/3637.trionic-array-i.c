/*
 * @lc app=leetcode id=3637 lang=c
 *
 * [3637] Trionic Array I
 */

// @lc code=start
bool isTrionic(int *nums, int numsSize)
{
    if (numsSize < 4)
        return false;
    if (nums[1] <= nums[0])
        return false;
    int cnt = 0;
    bool flag = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if ((flag && nums[i] < nums[i - 1]) ||
            (!flag && nums[i] > nums[i - 1]))
        {
            cnt++;
            flag = !flag;
        }
        else if (nums[i] == nums[i - 1])
            return false;
    }

    return cnt == 2;
}
// @lc code=end
