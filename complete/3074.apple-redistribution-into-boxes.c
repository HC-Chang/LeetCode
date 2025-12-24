/*
 * @lc app=leetcode id=3074 lang=c
 *
 * [3074] Apple Redistribution into Boxes
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int minimumBoxes(int *apple, int appleSize, int *capacity, int capacitySize)
{
    qsort(capacity, capacitySize, sizeof(int), sort);

    for (int i = 1; i < appleSize; i++)
        apple[0] += apple[i];

    int cnt = 0;
    while (apple[0] > 0 && cnt < capacitySize)
        apple[0] -= capacity[cnt++];
    return cnt;
}
// @lc code=end

// Note: sorting