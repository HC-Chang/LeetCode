/*
 * @lc app=leetcode id=2558 lang=cpp
 *
 * [2558] Take Gifts From the Richest Pile
 */

// Difficulty:Easy

// You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

// Choose the pile with the maximum number of gifts.
// If there is more than one pile with the maximum number of gifts, choose any.
// Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
// Return the number of gifts remaining after k seconds.

// Constraints:
// 1 <= gifts.length <= 103
// 1 <= gifts[i] <= 109
// 1 <= k <= 103

// @lc code=start
// Solution 2:

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq;
        long long sum = 0;
        for (auto g : gifts)
        {
            pq.push(g);
            sum += g;
        }

        int tmp;
        for (int i = 0; i < k; i++)
        {
            tmp = sqrt(pq.top());
            sum -= pq.top() - tmp;
            pq.pop();
            pq.push(tmp);
        }

        return sum;
    }
};
// @lc code=end

// Note: heap + simulation

// Solution 1:

// class Solution
// {
// public:
//     long long pickGifts(vector<int> &gifts, int k)
//     {
//         int n = gifts.size();
//         for (int i = 0; i < k; i++)
//         {
//             sort(gifts.begin(), gifts.end());
//             gifts[n - 1] = sqrt(gifts[n - 1]);
//         }

//         return accumulate(gifts.begin(), gifts.end(), (long long)0);
//     }
// };