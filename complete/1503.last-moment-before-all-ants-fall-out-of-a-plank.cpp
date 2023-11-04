/*
 * @lc app=leetcode id=1503 lang=cpp
 *
 * [1503] Last Moment Before All Ants Fall Out of a Plank
 */

// @lc code=start
class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int max_time = 0;
        for (auto &l : left)
            max_time = max(max_time, l);
        for (auto &r : right)
            max_time = max(max_time, n - r);
        return max_time;
    }
};
// @lc code=end
