/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        if (k % 2 == 0)
            return (kthGrammar(n - 1, k / 2) == 0) ? 1 : 0;
        return (kthGrammar(n - 1, (k + 1) / 2) == 0) ? 0 : 1;
    }
};
// @lc code=end
