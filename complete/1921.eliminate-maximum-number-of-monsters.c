/*
 * @lc app=leetcode id=1921 lang=c
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
int sort(void *a, void *b) { return *(double *)a > *(double *)b; }
int eliminateMaximum(int *dist, int distSize, int *speed, int speedSize)
{
    double time[distSize];

    for (int i = 0; i < distSize; i++)
        time[i] = (double)dist[i] / speed[i];

    qsort(&time, distSize, sizeof(double), sort);

    int count = 0;
    for (int i = 0; i < distSize; i++)
    {
        if ((double)i < time[i])
            count++;
        else
            break;
    }
    return count == distSize ? distSize : count;
}
// @lc code=end
