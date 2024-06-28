/*
 * @lc app=leetcode id=2285 lang=c
 *
 * [2285] Maximum Total Importance of Roads

 */

// @lc code=start
typedef struct
{
    int idx;
    int cnt;
    int val;
} DATA;

int sort1(void *a, void *b) { return ((DATA *)a)->cnt - ((DATA *)b)->cnt; }
int sort2(void *a, void *b) { return ((DATA *)a)->idx - ((DATA *)b)->idx; }

long long maximumImportance(int n, int **roads, int roadsSize,
                            int *roadsColSize)
{
    long long sum = 0;
    DATA d[n];
    for (int i = 0; i < n; i++)
    {
        d[i].idx = i;
        d[i].cnt = 0;
    }
    for (int i = 0; i < roadsSize; i++)
    {
        ++d[roads[i][0]].cnt;
        ++d[roads[i][1]].cnt;
    }

    qsort(&d, n, sizeof(DATA), sort1);
    for (int i = 0; i < n; i++)
        d[i].val = i + 1;
    qsort(&d, n, sizeof(DATA), sort2);

    for (int i = 0; i < roadsSize; i++)
        sum += d[roads[i][0]].val + d[roads[i][1]].val;

    return sum;
}
// @lc code=end

// Note: graph + sorting + heap