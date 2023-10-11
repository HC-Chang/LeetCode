/*
 * @lc app=leetcode id=2251 lang=c
 *
 * [2251] Number of Flowers in Full Bloom
 */

// @lc code=start
class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
    {
        int n = flowers.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; ++i)
        {
            starts[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int m = persons.size();
        vector<int> ans(m);
        int r, l;
        for (int i = 0; i < m; ++i)
        {
            r = upper_bound(starts.begin(), starts.end(), persons[i]) - starts.begin();
            l = lower_bound(ends.begin(), ends.end(), persons[i]) - ends.begin();
            ans[i] = r - l;
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table + binary search + sorting