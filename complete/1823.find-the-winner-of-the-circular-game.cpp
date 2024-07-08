/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        if (n == 1)
            return 1;
        int ans = (findTheWinner(n - 1, k) + k) % n;
        return ans == 0 ? n : ans;
    }
};
// @lc code=end

// Note: math + recursion + simulation