/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int nn = strs[0].size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < nn; j++)
            {
                if (strs[0][j] == -1)
                    continue;
                if (strs[i][j] - strs[i - 1][j] < 0)
                    strs[0][j] = -1;
            }
        }
        int count = 0;
        for (int i = 0; i < nn; i++)
        {
            if (strs[0][i] == -1)
                count++;
        }
        return count;
    }
};
// @lc code=end
