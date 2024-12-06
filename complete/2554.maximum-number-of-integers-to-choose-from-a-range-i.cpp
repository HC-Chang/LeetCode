/*
 * @lc app=leetcode id=2554 lang=cpp
 *
 * [2554] Maximum Number of Integers to Choose From a Range I
 */

// @lc code=start
class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        unordered_map<int, int> hash;
        for (auto b : banned)
            ++hash[b];
        int sum = 0;
        int cnt = 0;
        int boundary = fmin(maxSum, n);
        for (int i = 1; i <= boundary && sum + i <= maxSum; i++)
        {
            if (hash.find(i) != hash.end())
                continue;
            sum += i;
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

// Note: hash table + greedy