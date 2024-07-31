/*
 * @lc app=leetcode id=1105 lang=c
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
int minHeightShelves(int **books, int booksSize, int *booksColSize,
                     int shelfWidth)
{
    int dp[booksSize + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 0;
    dp[1] = books[0][1];

    int remaining_shelfWidth;
    int max_height;
    int j;
    for (int i = 1; i <= booksSize; ++i)
    {
        remaining_shelfWidth = shelfWidth - books[i - 1][0];
        max_height = books[i - 1][1];
        dp[i] = dp[i - 1] + max_height;

        j = i - 1;

        while (j > 0 && remaining_shelfWidth - books[j - 1][0] >= 0)
        {
            remaining_shelfWidth -= books[j - 1][0];
            max_height = fmax(max_height, books[j - 1][1]);
            dp[i] = fmin(dp[i], dp[j - 1] + max_height);
            j--;
        }
    }
    return dp[booksSize];
}
// @lc code=end

// Note: DP

// Official Solution