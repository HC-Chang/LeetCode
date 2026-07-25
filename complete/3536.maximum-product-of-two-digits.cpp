/*
 * @lc app=leetcode id=3536 lang=cpp
 *
 * [3536] Maximum Product of Two Digits
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(int n)
    {
        int first = INT_MIN;
        int second = INT_MIN;
        while (n)
        {
            int val = n % 10;
            if (val > first || first == INT_MIN)
            {
                if (first > second)
                    second = first;
                first = val;
            }
            else if (val > second)
                second = val;
            if (second > first)
                swap(first, second);
            n /= 10;
        }

        return first * second;
    }
};
// @lc code=end

// Note: math + sorting

// Solution : prioirity queue
// class Solution
// {
// public:
//     int maxProduct(int n)
//     {
//         priority_queue<int> pq;
//         while (n)
//         {
//             pq.push(n % 10);
//             n /= 10;
//         }
//         int ans = pq.top();
//         pq.pop();
//         return ans * pq.top();
//     }
// };