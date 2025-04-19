/*
 * @lc app=leetcode id=2491 lang=c
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
long long dividePlayers(int *skill, int skillSize)
{
    qsort(skill, skillSize, sizeof(int), sort);

    int val = skill[0] + skill[skillSize - 1];
    long long ans = skill[0] * skill[skillSize - 1];
    for (int i = 1; i < skillSize / 2; i++)
    {
        if (skill[i] + skill[skillSize - 1 - i] != val)
            return -1;
        ans += skill[i] * skill[skillSize - 1 - i];
    }
    return ans;
}
// @lc code=end

// Note: two pointers + sorting