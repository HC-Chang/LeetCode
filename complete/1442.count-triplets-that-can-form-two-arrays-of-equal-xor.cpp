/*
 * @lc app=leetcode id=1442 lang=cpp
 *
 * [1442] Count Triplets That Can Form Two Arrays of Equal XOR
 */

// @lc code=start
class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
            dp[i] = arr[i - 1] ^ dp[i - 1];

        int cnt = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (dp[i] == dp[j])
                    cnt += j - i - 1;
            }
        }
        return cnt;
    }
};
// @lc code=end

// Note: prefix sum