/*
 * @lc app=leetcode id=3494 lang=c
 *
 * [3494] Find the Minimum Amount of Time to Brew Potions
 */

// @lc code=start
long long minTime(int *skill, int skillSize, int *mana, int manaSize)
{
    long long times[skillSize];
    memset(times, 0, sizeof(times));
    for (int j = 0; j < manaSize; j++)
    {
        long long cur_time = 0;
        for (int i = 0; i < skillSize; i++)
            cur_time = fmax(cur_time, times[i]) + skill[i] * mana[j];

        times[skillSize - 1] = cur_time;
        for (int i = skillSize - 2; i >= 0; i--)
            times[i] = times[i + 1] - skill[i + 1] * mana[j];
    }
    return times[skillSize - 1];
}
// @lc code=end

// Note: prefix sum + simulation

// Official Solution
