/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 */

// @lc code=start
class Solution
{
public:
    void arr_sort(int i, int j, vector<vector<int>> &mat, int m, int n)
    {
        vector<int> arr;
        for (int ii = i, jj = j; ii < m && jj < n; ii++, jj++)
            arr.push_back(mat[ii][jj]);
        sort(arr.begin(), arr.end());
        int idx = 0;
        for (int ii = i, jj = j; ii < m && jj < n; ii++, jj++)
            mat[ii][jj] = arr[idx++];
    }

    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++)
            arr_sort(i, 0, mat, m, n);
        for (int i = 1; i < n; i++)
            arr_sort(0, i, mat, m, n);

        return mat;
    }
};
// @lc code=end

// Note: sorting