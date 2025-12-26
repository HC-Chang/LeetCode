/*
 * @lc app=leetcode id=2483 lang=cpp
 *
 * [2483] Minimum Penalty for a Shop

 */

// @lc code=start
class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();

        int y_total = 0;
        for (const auto c : customers)
        {
            if (c == 'Y')
                y_total++;
        }

        int t = 0;
        int min = INT_MAX;
        int y_count = 0;
        int n_count = 0;
        int cur;
        for (int i = 0; i <= n; i++)
        {
            cur = n_count + y_total - y_count;
            if (cur < min)
            {
                min = cur;
                t = i;
            }
            if (i == n)
                continue;
            if (customers[i] == 'Y')
                y_count++;
            else
                n_count++;
        }
        return t;
    }
};
// @lc code=end

// Note: prefix sum
