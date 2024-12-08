/*
 * @lc app=leetcode id=2054 lang=cpp
 *
 * [2054] Two Best Non-Overlapping Events
 */

// @lc code=start
class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        vector<array<int, 3>> times;
        for (auto &e : events)
        {
            times.push_back({e[0], 1, e[2]});
            times.push_back({e[1] + 1, 0, e[2]});
        }

        int ans = 0, max_val = 0;
        sort(begin(times), end(times));
        for (auto &t : times)
        {
            if (t[1])
                ans = max(ans, t[2] + max_val);
            else
                max_val = max(max_val, t[2]);
        }

        return ans;
    }
};
// @lc code=end

// Note: sorting + binary search + heap