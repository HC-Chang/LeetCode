/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int res = 0;
        int n = customers.size();
        int mx = 0;
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i)
        {
            sums[i + 1] = sums[i];
            if (grumpy[i] == 0)
                res += customers[i];
            else
                sums[i + 1] += customers[i];
            if (i + 1 - minutes >= 0)
                mx = max(mx, sums[i + 1] - sums[i + 1 - minutes]);
        }
        return res + mx;
    }
};
// @lc code=end
