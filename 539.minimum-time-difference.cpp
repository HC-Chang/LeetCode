/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        int n = timePoints.size();
        vector<int> t(n);
        for (int i = 0; i < n; i++)
            t[i] = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2));

        sort(t.begin(), t.end());
        int tt = t[0];
        for (int i = 0; i < n - 1; i++)
            t[i] = t[i + 1] - t[i];
        t[n - 1] = 1440 + tt - t[n - 1];
        sort(t.begin(), t.end());
        return t[0];
    }
};
// @lc code=end

// Note: math + sorting