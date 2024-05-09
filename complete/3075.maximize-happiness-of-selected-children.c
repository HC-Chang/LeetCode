/*
 * @lc app=leetcode id=3075 lang=c
 *
 * [3075] Maximize Happiness of Selected Children
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)b - *(int *)a; }
long long maximumHappinessSum(int *happiness, int happinessSize, int k)
{
    qsort(happiness, happinessSize, sizeof(int), sort);
    long long sum = 0;
    for (int i = 0; i < k; i++)
    {
        if (happiness[i] - i <= 0)
            break;
        sum += happiness[i] - i;
    }
    return sum;
}
// @lc code=end

// Note: sorting