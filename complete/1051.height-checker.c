/*
 * @lc app=leetcode id=1051 lang=c
 *
 * [1051] Height Checker
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int heightChecker(int *heights, int heightsSize)
{
    int sorted[heightsSize];
    memcpy(&sorted, heights, sizeof(sorted));
    qsort(&sorted, heightsSize, sizeof(int), sort);

    int cnt = 0;
    for (int i = 0; i < heightsSize; i++)
    {
        if (sorted[i] != heights[i])
            cnt++;
    }
    return cnt;
}
// @lc code=end

// Note: sorting