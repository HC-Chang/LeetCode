/*
 * @lc app=leetcode id=3105 lang=c
 *
 * [3105] Longest Strictly Increasing or Strictly Decreasing Subarray
 */

// @lc code=start
int longestMonotonicSubarray(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize;
    int cnt = 1;
    int tmp_cnt = 1;

    int pn = nums[0] - nums[1];
    if (pn != 0)
        tmp_cnt++;

    int tmp_pn;
    for (int i = 1; i < numsSize - 1; i++)
    {
        tmp_pn = nums[i] - nums[i + 1];
        if (pn * tmp_pn <= 0)
        {
            if (tmp_cnt > cnt)
                cnt = tmp_cnt;
            pn = tmp_pn;
            if (tmp_pn == 0)
                tmp_cnt = 1;
            else
                tmp_cnt = 2;
        }
        else
            tmp_cnt++;
    }

    if (tmp_cnt > cnt)
        return tmp_cnt;
    return cnt;
}
// @lc code=end
