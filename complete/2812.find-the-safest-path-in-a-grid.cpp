/*
 * @lc app=leetcode id=2812 lang=cpp
 *
 * [2812] Find the Safest Path in a Grid
 */

// @lc code=start
#define PAIR pair<int, int>
class Solution
{
public:
    vector<PAIR> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool is_pass(int d, vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));

        if (grid[0][0] <= d)
            return false;

        queue<PAIR> q;
        q.push({0, 0});
        visited[0][0] = 1;

        int i, j;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                i = x + dir[k].first;
                j = y + dir[k].second;
                if (i < 0 || i >= n || j < 0 || j >= n)
                    continue;
                if (grid[i][j] <= d)
                    continue;
                if (visited[i][j])
                    continue;

                visited[i][j] = 1;
                if (i == n - 1 && j == n - 1)
                    return true;
                q.push({i, j});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();

        queue<PAIR> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    q.push({i, j});

        int i, j;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    i = x + dir[k].first;
                    j = y + dir[k].second;
                    if (i < 0 || i >= n || j < 0 || j >= n)
                        continue;
                    if (grid[i][j] != 0)
                        continue;
                    grid[i][j] = grid[x][y] + 1;
                    q.push({i, j});
                }
            }
        }

        int left = 0, right = n;
        int mid;
        while (left < right)
        {
            mid = right - (right - left) / 2;
            if (is_pass(mid, grid))
                left = mid;
            else
                right = mid - 1;
        }

        return left;
    }
};
// @lc code=end

// Note: BFS + binary search + matrix