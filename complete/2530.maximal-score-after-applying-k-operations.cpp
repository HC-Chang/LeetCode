/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 */

// Difficulty:Easy

// @lc code=start
class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long int sum = 0;
        priority_queue<int> pq;
        for (auto &i : nums)
            pq.push(i);

        while (k--)
        {
            int maxElement = pq.top();
            sum += maxElement;
            pq.pop();
            pq.push(ceil(maxElement / 3.0));
        }
        return sum;
    }
};
// @lc code=end

// Note: heap

// Official Solution