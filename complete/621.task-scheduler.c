/*
 * @lc app=leetcode id=621 lang=c
 *
 * [621] Task Scheduler
 */

// @lc code=start
int max(int a, int b) { return a > b ? a : b; }

int leastInterval(char *tasks, int tasksSize, int n)
{
    if (n == 0)
        return tasksSize;
    int hash[26] = {0};
    for (int i = 0; i < tasksSize; i++)
        hash[tasks[i] - 'A']++;

    int max_count = 0;
    int remain = 0;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_count)
        {
            max_count = hash[i];
            remain = 1;
        }
        else if (hash[i] == max_count)
            remain++;
    }

    int r = (max_count - 1) * (n + 1) + remain;
    return max(r, tasksSize);
}
// @lc code=end
