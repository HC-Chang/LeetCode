/*
 * @lc app=leetcode id=2078 lang=cpp
 *
 * [2078] Two Furthest Houses With Different Colors
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int n = colors.size();
        int l1 = 0;
        int r1 = n - 1;
        int l2 = -1;
        int r2 = -1;
        for (int i = 1; i < n && (l2 == -1 || r2 == -1); i++)
        {
            if (l2 == -1 && colors[i] != colors[0])
                l2 = i;
            if (r2 == -1 && colors[n - 1 - i] != colors[n - 1])
                r2 = n - 1 - i;
        }

        if (colors[0] != colors[n - 1])
            return r1 - l1;
        return max(r1 - l2, r2 - l1);
    }
};
// @lc code=end
