/*
 * @lc app=leetcode id=2257 lang=cpp
 *
 * [2257] Count Unguarded Cells in the Grid
 */

// @lc code=start
class Solution
{
public:
    enum
    {
        UNGUARDED = 0,
        GUARDED,
        GUARD,
        WALL
    };
    int countUnguarded(int m, int n, vector<vector<int>> &guards,
                       vector<vector<int>> &walls)
    {
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));
        auto updateCellVisibility = [&](int row, int col,
                                        bool isGuardLineActive) -> bool
        {
            if (grid[row][col] == GUARD)
                return true;

            if (grid[row][col] == WALL)
                return false;

            if (isGuardLineActive)
                grid[row][col] = GUARDED;

            return isGuardLineActive;
        };

        for (const auto &guard : guards)
            grid[guard[0]][guard[1]] = GUARD;

        for (const auto &wall : walls)
            grid[wall[0]][wall[1]] = WALL;

        for (int row = 0; row < m; row++)
        {
            bool isGuardLineActive = grid[row][0] == GUARD;
            for (int col = 1; col < n; col++)
                isGuardLineActive =
                    updateCellVisibility(row, col, isGuardLineActive);

            isGuardLineActive = grid[row][n - 1] == GUARD;
            for (int col = n - 2; col >= 0; col--)
                isGuardLineActive =
                    updateCellVisibility(row, col, isGuardLineActive);
        }

        for (int col = 0; col < n; col++)
        {
            bool isGuardLineActive = grid[0][col] == GUARD;
            for (int row = 1; row < m; row++)
                isGuardLineActive =
                    updateCellVisibility(row, col, isGuardLineActive);

            isGuardLineActive = grid[m - 1][col] == GUARD;
            for (int row = m - 2; row >= 0; row--)
                isGuardLineActive =
                    updateCellVisibility(row, col, isGuardLineActive);
        }

        int count = 0;
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == UNGUARDED)
                    count++;
            }
        }

        return count;
    }
};
// @lc code=end

// Note: matrix