/*
 * @lc app=leetcode id=673 lang=c
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
int findNumberOfLIS(int *nums, int numsSize)
{
    int res = 0;
    int max = 0;
    int *len = malloc(numsSize * sizeof(int));
    int *cnt = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        len[i] = 1;
        cnt[i] = 1;
    }

    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] <= nums[j])
                continue;
            if (len[i] == len[j] + 1)
                cnt[i] += cnt[j];
            else if (len[i] < len[j] + 1)
            {
                len[i] = len[j] + 1;
                cnt[i] = cnt[j];
            }
        }
        max = fmax(max, len[i]);
    }
    for (int i = 0; i < numsSize; ++i)
    {
        if (max == len[i])
            res += cnt[i];
    }
    free(len);
    free(cnt);
    return res;
}
// @lc code=end
