/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
    vector<vector<int>> prefix;

private:
    Node *dfs(int x, int y, int size)
    {
        int sum = prefix[x + size][y + size] - prefix[x + size][y] - prefix[x][y + size] + prefix[x][y];
        if (size * size == sum || sum == 0)
            return new Node(sum, true);
        return new Node(true, false,
                        dfs(x, y, size / 2),
                        dfs(x, y + size / 2, size / 2),
                        dfs(x + size / 2, y, size / 2),
                        dfs(x + size / 2, y + size / 2, size / 2));
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        int size = grid.size();
        prefix.assign(size + 1, vector<int>(size + 1));
        int sum;
        for (int i = 0; i < size; ++i)
        {
            sum = 0;
            for (int j = 0; j < size; ++j)
            {
                sum += grid[i][j];
                prefix[i + 1][j + 1] = sum + prefix[i][j + 1];
            }
        }
        return dfs(0, 0, grid.size());
    }
};
// @lc code=end