/*
 * @lc app=leetcode id=2210 lang=c
 *
 * [2210] Count Hills and Valleys in an Array
 */

// @lc code=start
int countHillValley(int *nums, int numsSize)
{
    int cnt = 0;
    int l;
    int r;
    for (int i = 1; i < numsSize - 1; i++)
    {
        l = i - 1;
        r = i + 1;
        while (l - 1 >= 0 && nums[l] == nums[i])
            l--;
        while (r + 1 < numsSize && nums[r] == nums[i])
            r++;
        if ((nums[i] > nums[l] && nums[i] > nums[r]) || (nums[i] < nums[l] && nums[i] < nums[r]))
            cnt++;
        i = r - 1;
    }

    return cnt;
}
// @lc code=end
