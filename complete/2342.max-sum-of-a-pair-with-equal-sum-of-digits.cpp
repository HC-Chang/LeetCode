/*
 * @lc app=leetcode id=2342 lang=cpp
 *
 * [2342] Max Sum of a Pair With Equal Sum of Digits
 */

// @lc code=start
class Solution
{
public:
    int sum_of_digits(int val)
    {
        int v = 0;
        while (val > 0)
        {
            v += val % 10;
            val /= 10;
        }
        return v;
    }
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, priority_queue<int>> hash;
        for (auto n : nums)
            hash[sum_of_digits(n)].push(n);

        int ans = -1;
        for (auto h : hash)
        {
            if (h.second.size() >= 2)
            {
                int tmp = h.second.top();
                h.second.pop();
                tmp += h.second.top();
                if (tmp > ans)
                    ans = tmp;
            }
        }

        return ans;
    }
};
// @lc code=end

// Note: hash table + sorting + heap