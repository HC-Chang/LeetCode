/*
 * @lc app=leetcode id=624 lang=cpp
 *
 * [624] Maximum Distance in Arrays
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int n = arrays.size();
        int mmin = arrays[0][0];
        int mmax = arrays[0][arrays[0].size() - 1];
        int res = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            res = max(res, abs(arrays[i][0] - mmax));
            res = max(res, abs(arrays[i][arrays[i].size() - 1] - mmin));
            mmax = max(mmax, arrays[i][arrays[i].size() - 1]);
            mmin = min(mmin, arrays[i][0]);
        }
        return res;
    }
};
// @lc code=end

// Note: greedy