/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution
{
public:
    int binary_search(const vector<int> &arr, int arrSize)
    {
        int left = 0;
        int right = arrSize - 1;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (arr[mid] < 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return arrSize - left;
    }

    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        int n = grid.size();
        int nn = grid[0].size();
        for (int i = 0; i < n; i++)
            count += binary_search(grid[i], nn);
        return count;
    }
};
// @lc code=end

// Note: binary search