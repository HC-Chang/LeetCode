/*
 * @lc app=leetcode id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */

// @lc code=start
class Solution
{
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int dp[n1][n2];
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                dp[i][j] = nums1[i] * nums2[j];
                if (i > 0 && j > 0)
                    dp[i][j] += max(0, dp[i - 1][j - 1]);
                if (i > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j > 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[n1 - 1][n2 - 1];
    }
};
// @lc code=end

// Note: DP