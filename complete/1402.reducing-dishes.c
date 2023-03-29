/*
 * @lc app=leetcode id=1402 lang=c
 *
 * [1402] Reducing Dishes
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)b - *(int *)a; }
int max(int a, int b) { return a > b ? a : b; }
int maxSatisfaction(int *satisfaction, int satisfactionSize)
{
    qsort(satisfaction, satisfactionSize, sizeof(int), sort);

    int total = 0, presum = 0;
    int r = INT_MIN;
    for (int i = 0; i < satisfactionSize; i++)
    {
        presum += satisfaction[i];
        total += presum;
        r = max(r, total);
    }
    return max(0, r);
}

// @lc code=end

// Note: sorting + DP