/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start

class Solution
{
public:
    int orangesRotting(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        std::queue<std::pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    q.emplace(i, j);
            }
        }

        std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minutes = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool rotten = false;
            for (int i = 0; i < size; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (auto &d : dirs)
                {
                    int nx = x + d.first;
                    int ny = y + d.second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.emplace(nx, ny);
                        rotten = true;
                    }
                }
            }
            if (rotten)
                minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
// @lc code=end

// Note: BFS + queue