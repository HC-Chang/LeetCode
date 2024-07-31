/*
 * @lc app=leetcode id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        vector<int> dp(n + 1, 0);

        dp[1] = books[0][1];

        int remaining_shelfWidth;
        int max_height;
        int j;

        for (int i = 1; i <= n; ++i)
        {
            remaining_shelfWidth = shelfWidth - books[i - 1][0];
            max_height = books[i - 1][1];
            dp[i] = dp[i - 1] + max_height;

            j = i - 1;

            while (j > 0 && remaining_shelfWidth - books[j - 1][0] >= 0)
            {
                remaining_shelfWidth -= books[j - 1][0];
                max_height = max(max_height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + max_height);
                j--;
            }
        }

        return dp[n];
    }
};
// @lc code=end

// Note: DP

// Official Solution