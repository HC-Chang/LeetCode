/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
class Solution
{
public:
    int minPartitions(string n)
    {
        for (auto nn : n)
        {
            if (nn > n[0])
                n[0] = nn;
        }
        return n[0] - '0';
    }
};
// @lc code=end

// Note: greedy