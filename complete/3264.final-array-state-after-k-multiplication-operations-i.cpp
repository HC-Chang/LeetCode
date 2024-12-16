/*
 * @lc app=leetcode id=3264 lang=cpp
 *
 * [3264] Final Array State After K Multiplication Operations I
 */

// @lc code=start
class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        for (int i = 0; i < k; i++)
        {
            pair<int, int> p = pq.top();
            pq.pop();
            p.first *= multiplier;
            pq.push(p);
        }

        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            nums[p.second] = p.first;
        }
        return nums;
    }
};
// @lc code=end

// Note: heap