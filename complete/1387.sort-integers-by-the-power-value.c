/*
 * @lc app=leetcode id=1387 lang=c
 *
 * [1387] Sort Integers by The Power Value
 */

// @lc code=start
typedef struct
{
    int idx;
    int val;
} DATA;

int sort(void *a, void *b)
{
    return ((DATA *)a)->val - ((DATA *)b)->val;
}

int getKth(int lo, int hi, int k)
{
    DATA d[hi - lo + 1];
    memset(d, 0, sizeof(d));

    int cur;
    int last_val;
    for (int i = lo; i <= hi; i++)
    {
        d[i - lo].idx = i;
        cur = i;
        last_val = 0;
        while (cur > 1)
        {
            if (cur % 2 == 0)
                cur /= 2;
            else
                cur = cur * 3 + 1;
            ++last_val;
        }
        d[i - lo].val = last_val;
    }

    qsort(d, hi - lo + 1, sizeof(DATA), sort);
    return d[k - 1].idx;
}
// @lc code=end

// Note: sort