/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        int res = 0;
        set<vector<vector<int>>> visited;
        queue<pair<vector<vector<int>>, vector<int>>> q;
        vector<vector<int>> correct{{1, 2, 3}, {4, 5, 0}};
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == 0)
                    q.push({board, {i, j}});
            }
        }

        while (!q.empty())
        {
            for (int i = q.size() - 1; i >= 0; --i)
            {
                auto t = q.front().first;
                auto zero = q.front().second;
                q.pop();
                if (t == correct)
                    return res;
                visited.insert(t);
                for (auto d : dirs)
                {
                    int x = zero[0] + d[0], y = zero[1] + d[1];
                    if (x < 0 || x >= 2 || y < 0 || y >= 3)
                        continue;
                    vector<vector<int>> cand = t;
                    swap(cand[zero[0]][zero[1]], cand[x][y]);
                    if (visited.count(cand))
                        continue;
                    q.push({cand, {x, y}});
                }
            }
            ++res;
        }

        return -1;
    }
};
// @lc code=end

// Note: bfs + matrix