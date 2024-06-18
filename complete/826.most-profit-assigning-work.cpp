/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<pair<int, int>> p;
        int n = difficulty.size();
        for (int i = 0; i < n; i++)
            p.emplace_back(difficulty[i], profit[i]);

        sort(p.begin(), p.end());
        for (int i = 1; i < n; i++)
            p[i].second = max(p[i].second, p[i - 1].second);
        sort(worker.begin(), worker.end());

        if (worker[worker.size() - 1] < p[0].first)
            return 0;
        int sum = 0;
        int idx = 0;
        for (int i = 0; i < worker.size(); i++)
        {
            if (worker[i] < p[idx].first)
                continue;
            while (idx + 1 < n && worker[i] >= p[idx + 1].first)
                idx++;
            sum += p[idx].second;
        }

        return sum;
    }
};
// @lc code=end

// Note: sorting