/*
 * @lc app=leetcode id=1387 lang=c
 *
 * [1387] Sort Integers by The Power Value
 */

// @lc code=start
class Solution
{
public:
    typedef struct
    {
        int idx;
        int val;
    } DATA;

    int getKth(int lo, int hi, int k)
    {
        vector<DATA> d(hi - lo + 1);
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
        sort(d.begin(), d.end(), [](const DATA &a, const DATA &b)
             {
            if(a.val == b.val)
                return a.idx < b.idx;
            return a.val < b.val; });
        return d[k - 1].idx;
    }
};
// @lc code=end

// Note: sort