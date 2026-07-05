/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int dirs[5] = {0, -1, 0, 1, 0};
        queue<pair<int, int>> q;
        int x, y, tx, ty;

        q.push({entrance[1], entrance[0]});

        for (int steps = 0; !q.empty(); ++steps)
        {
            for (int s = q.size(); s; --s)
            {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                if (x == 0 || x == maze[0].size() - 1 || y == 0 ||
                    y == maze.size() - 1)
                    if (x != entrance[1] || y != entrance[0])
                        return steps;

                for (int i = 0; i < 4; ++i)
                {
                    tx = x + dirs[i];
                    ty = y + dirs[i + 1];
                    if (tx < 0 || tx >= maze[0].size() || ty < 0 ||
                        ty >= maze.size() || maze[ty][tx] != '.')
                        continue;
                    maze[ty][tx] = '*';
                    q.push({tx, ty});
                }
            }
        }
        return -1;
    }
};
// @lc code=end

// Note: BFS