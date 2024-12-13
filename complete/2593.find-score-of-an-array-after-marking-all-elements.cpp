/*
 * @lc app=leetcode id=2593 lang=cpp
 *
 * [2593] Find Score of an Array After Marking All Elements
 */

// @lc code=start
class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        long long score = 0;
        vector<int> visited(n);

        int val;
        int idx;
        while (!pq.empty())
        {
            val = pq.top().first;
            idx = pq.top().second;
            pq.pop();

            if (visited[idx])
                continue;

            score += val;
            visited[idx] = 1;

            if (idx - 1 >= 0)
                visited[idx - 1] = 1;

            if (idx + 1 < n)
                visited[idx + 1] = 1;
        }

        return score;
    }
};
// @lc code=end

// Note: heap + sorting + greedy