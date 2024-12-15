/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 */

// @lc code=start
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        auto diff_ratio = [](int passes, int totalStudents)
        {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };

        priority_queue<pair<double, pair<int, int>>> pq;
        for (const auto &singleClass : classes)
            pq.push({diff_ratio(singleClass[0], singleClass[1]), {singleClass[0], singleClass[1]}});

        while (extraStudents--)
        {
            auto tmp = pq.top();
            pq.pop();
            int passes = tmp.second.first;
            int totalStudents = tmp.second.second;
            pq.push({diff_ratio(passes + 1, totalStudents + 1),
                     {passes + 1, totalStudents + 1}});
        }

        double totalPassRatio = 0;
        while (!pq.empty())
        {
            auto tmp = pq.top();
            pq.pop();
            totalPassRatio += (double)tmp.second.first / tmp.second.second;
        }

        return totalPassRatio / classes.size();
    }
};
// @lc code=end

// Note: greedy + heap

// Official Soultion