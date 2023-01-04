/*
 * @lc app=leetcode id=2244 lang=c
 *
 * [2244] Minimum Rounds to Complete All Tasks
 */

// @lc code=start
int sort(void *a, void *b)
{
    return *(int *)a > *(int *)b ? 1 : 0;
}

int minimumRounds(int *tasks, int tasksSize)
{
    if (tasksSize == 1)
        return -1;
    qsort(tasks, tasksSize, sizeof(int), sort);
    int count = 0;
    int tmp = tasks[0];
    int tmp_count = 1;
    for (int i = 1; i < tasksSize; i++)
    {
        if (tmp == tasks[i])
            tmp_count++;
        else if (tmp_count == 1)
            return -1;
        else
        {
            count += (tmp_count - 1) / 3 + 1;
            tmp = tasks[i];
            tmp_count = 1;
        }
    }
    if (tmp_count == 1)
        return -1;
    else
        count += (tmp_count - 1) / 3 + 1;

    return count;
}

// @lc code=end

// 1 -1
// 2 1
// 3 1
// 4 2
// 5 2
// 6 2
// 7 3
// 8 3
// 9 3
// 10 4
// 11 4
// 12 4
// 13 5
// 14 5
// 15 5