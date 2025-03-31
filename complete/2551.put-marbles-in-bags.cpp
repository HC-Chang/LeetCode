/*
 * @lc app=leetcode id=2551 lang=cpp
 *
 * [2551]  Put Marbles in Bags
 */

// @lc code=start
class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        if (n == 1)
            return 0;
        vector<long long> arr(n - 1);
        for (int i = 0; i < n - 1; i++)
            arr[i] = weights[i] + weights[i + 1];
        sort(arr.begin(), arr.end());

        long long r = 0;
        for (int i = 0; i < k - 1; i++)
            r += arr[n - 2 - i] - arr[i];

        return r;
    }
};
// @lc code=end