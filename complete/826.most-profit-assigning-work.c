/*
 * @lc app=leetcode id=826 lang=c
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
typedef struct
{
    int di;
    int pr;
} DATA;
int sort1(void *a, void *b) { return ((DATA *)a)->di - ((DATA *)b)->di; }
int sort2(void *a, void *b) { return *(int *)a - *(int *)b; }
int maxProfitAssignment(int *difficulty, int difficultySize, int *profit, int profitSize, int *worker, int workerSize)
{
    int n = difficultySize;
    DATA d[n];
    for (int i = 0; i < n; i++)
    {
        d[i].di = difficulty[i];
        d[i].pr = profit[i];
    }

    qsort(d, n, sizeof(DATA), sort1);
    for (int i = 1; i < n; i++)
        d[i].pr = fmax(d[i].pr, d[i - 1].pr);
    qsort(worker, workerSize, sizeof(int), sort2);

    if (worker[workerSize - 1] < d[0].di)
        return 0;
    int sum = 0;
    int idx = 0;
    for (int i = 0; i < workerSize; i++)
    {
        if (worker[i] < d[idx].di)
            continue;
        while (idx + 1 < n && worker[i] >= d[idx + 1].di)
            idx++;
        sum += d[idx].pr;
    }

    return sum;
}
// @lc code=end

// Note: sorting