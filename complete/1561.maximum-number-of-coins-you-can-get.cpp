/*
 * @lc app=leetcode id=1561 lang=c
 *
 * [1561] Maximum Number of Coins You Can Get
 */

// @lc code=start
class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end(), greater<int>());
        int n = piles.size() / 3;
        for (int i = 1; i < n; i++)
            piles[1] += piles[i * 2 + 1];

        return piles[1];
    }
};
// @lc code=end
