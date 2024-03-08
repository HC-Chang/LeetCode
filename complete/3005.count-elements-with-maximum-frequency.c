/*
 * @lc app=leetcode id=3005 lang=c
 *
 * [3005] Count Elements With Maximum Frequency
 */

// @lc code=start
int maxFrequencyElements(int *nums, int numsSize)
{
    int cnt[101] = {0};
    int max_cnt = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (++cnt[nums[i]] > max_cnt)
            max_cnt = cnt[nums[i]];
    }
    int max = 0;
    for (int i = 0; i < 101; i++)
    {
        if (cnt[i] == max_cnt)
            max += cnt[i];
    }
    return max;
}
// @lc code=end

// Note: hash table + counting