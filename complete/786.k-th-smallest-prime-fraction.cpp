/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 */

// @lc code=start
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        int n = arr.size();
        auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y)
        {
            return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int j = 1; j < n; ++j)
        {
            q.emplace(0, j);
        }
        for (int _ = 1; _ < k; ++_)
        {
            auto [i, j] = q.top();
            q.pop();
            if (i + 1 < j)
            {
                q.emplace(i + 1, j);
            }
        }
        return {arr[q.top().first], arr[q.top().second]};
    }
};
// @lc code=end

// Note: sorting / heap

// Official Solution