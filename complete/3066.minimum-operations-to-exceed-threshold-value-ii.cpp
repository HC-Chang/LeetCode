/*
 * @lc app=leetcode id=3066 lang=cpp
 *
 * [3066] Minimum Operations to Exceed Threshold Value II
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int op_cnt = 0;
        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;
        for (auto n : nums)
            pq.push(n);
        int64_t tmp1;
        int64_t tmp2;
        while (pq.top() < k)
        {
            tmp1 = pq.top();
            pq.pop();
            tmp2 = pq.top();
            pq.pop();
            pq.push(tmp1 * 2 + tmp2);
            ++op_cnt;
        }
        return op_cnt;
    }
};
// @lc code=end

// Note heap + simulation