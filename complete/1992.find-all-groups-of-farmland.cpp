/*
 * @lc app=leetcode id=1992 lang=cpp
 *
 * [1992] Find All Groups of Farmland
 */

// @lc code=start
class Solution
{
public:
    void bfs(int i, int j, vector<vector<int>> &ans, int m, int n,
             vector<vector<int>> &land)
    {
        vector<int> tmp(4);
        tmp[0] = i;
        tmp[1] = j;
        int ii = i;
        int jj = j;
        while (ii + 1 < m && land[ii + 1][j] == 1)
            ii++;
        while (jj + 1 < n && land[i][jj + 1] == 1)
            jj++;

        land[i][j] = 0;
        for (int x = i; x <= ii; x++)
        {
            for (int y = j; y <= jj; y++)
                land[x][y] = 0;
        }
        tmp[2] = ii;
        tmp[3] = jj;
        ans.push_back(tmp);
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j])
                    bfs(i, j, ans, m, n, land);
            }
        }

        return ans;
    }
};
// @lc code=end

// Note: DFS / BFS + matrix