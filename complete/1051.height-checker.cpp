/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> sorted(heights);
        sort(sorted.begin(), sorted.end());

        int cnt = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (sorted[i] != heights[i])
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end

// Note: sorting