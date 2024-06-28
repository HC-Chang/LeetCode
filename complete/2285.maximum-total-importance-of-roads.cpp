/*
 * @lc app=leetcode id=2285 lang=cpp
 *
 * [2285] Maximum Total Importance of Roads

 */

// @lc code=start
class Solution
{
public:
    typedef struct
    {
        int idx;
        int cnt;
        int val;
    } DATA;

    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        long long sum = 0;
        int roadsSize = roads.size();
        vector<DATA> d(n);
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

        sort(d.begin(), d.end(), [](DATA a, DATA b)
             { return a.cnt < b.cnt; });

        for (int i = 0; i < n; i++)
            d[i].val = i + 1;

        sort(d.begin(), d.end(), [](DATA a, DATA b)
             { return a.idx < b.idx; });

        for (int i = 0; i < roadsSize; i++)
            sum += d[roads[i][0]].val + d[roads[i][1]].val;

        return sum;
    }
};
// @lc code=end

// Note: graph + sorting + heap