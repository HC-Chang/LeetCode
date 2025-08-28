/*
 * @lc app=leetcode id=3446 lang=cpp
 *
 * [3446] Sort Matrix by Diagonals
 */

// @lc code=start
class Solution
{
public:
    void sort_arr(int i, int j, int m, int n, int decrease, vector<vector<int>> &grid)
    {
        vector<int> arr;
        int k = i;
        int l = j;
        while (k < m && l < n)
            arr.push_back(grid[k++][l++]);
        if (decrease)
            sort(arr.begin(), arr.end(), greater<int>());
        else
            sort(arr.begin(), arr.end());
        int idx = 0;
        while (i < m && j < n)
            grid[i++][j++] = arr[idx++];
    }

    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = m - 1; i >= 0; i--)
            sort_arr(i, 0, m, n, 1, grid);

        for (int i = 1; i < n; i++)
            sort_arr(0, i, m, n, 0, grid);
        return grid;
    }
};
// @lc code=end

// Note: sorting + matrix
