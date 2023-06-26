/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */

// @lc code=start
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int left = 0;
        int right = costs.size() - 1;
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;

        long long t_cost = 0;
        int v1, v2;
        while (k--)
        {
            while (pq1.size() < candidates && left <= right)
                pq1.push(costs[left++]);

            while (pq2.size() < candidates && left <= right)
                pq2.push(costs[right--]);

            v1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            v2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (v1 <= v2)
            {
                t_cost += v1;
                pq1.pop();
            }
            else
            {
                t_cost += v2;
                pq2.pop();
            }
        }
        return t_cost;
    }
};
// @lc code=end
