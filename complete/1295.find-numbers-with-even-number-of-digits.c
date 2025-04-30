/*
 * @lc app=leetcode id=1295 lang=c
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
int findNumbers(int *nums, int numsSize)
{
    int cnt = 0;
    int tmp_cnt;
    for (int i = 0; i < numsSize; i++)
    {
        tmp_cnt = 0;
        while (nums[i])
        {
            nums[i] /= 10;
            ++tmp_cnt;
        }
        if (tmp_cnt % 2 == 0)
            cnt++;
    }

    return cnt;
}
// @lc code=end
