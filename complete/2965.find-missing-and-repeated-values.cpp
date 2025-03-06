/*
 * @lc app=leetcode id=2965 lang=cpp
 *
 * [2965] Find Missing and Repeated Values
 */

// @lc code=start
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size() * grid.size();
        vector<int> arr(n + 1);
        int a1, a2;
        for (auto x : grid)
        {
            for (auto y : x)
            {
                if (++arr[y] == 2)
                    a1 = y;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == 0)
            {
                a2 = i;
                break;
            }
        }
        return {a1, a2};
    }
};
// @lc code=end

// Note: hash table