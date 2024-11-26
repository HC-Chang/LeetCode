/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

// @lc code=start
class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> indegree(n);
        for (auto e : edges)
            indegree[e[1]]++;

        int champ = -1;
        int champCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                champCount++;
                champ = i;
            }
        }

        return champCount > 1 ? -1 : champ;
    }
};
// @lc code=end

// Note: graph

// Official Solution