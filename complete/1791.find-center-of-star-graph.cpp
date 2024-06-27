/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        unordered_map<int, int> hash;
        for (auto e : edges)
        {
            if (++hash[e[0]] >= 2)
                return e[0];
            if (++hash[e[1]] >= 2)
                return e[1];
        }
        return -1;
    }
};
// @lc code=end

// Note: graph