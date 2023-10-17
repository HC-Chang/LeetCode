/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */

// @lc code=start
class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        int arr[n];
        memset(arr, 0, sizeof(arr));
        for (int i : leftChild)
            if (i != -1)
                arr[i]++;
        for (int i : rightChild)
            if (i != -1)
                arr[i]++;

        int root = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                if (root != -1)
                    return false;
                root = i;
            }
        }
        if (root == -1)
            return false;

        unordered_set<int> visited = {root};
        queue<int> q;
        q.push(root);
        while (!q.empty())
        {
            int pre = q.front();
            q.pop();
            if (leftChild[pre] != -1)
            {
                if (visited.count(leftChild[pre]))
                    return false;
                visited.insert(leftChild[pre]);
                q.push(leftChild[pre]);
            }
            if (rightChild[pre] != -1)
            {
                if (visited.count(rightChild[pre]))
                    return false;
                visited.insert(rightChild[pre]);
                q.push(rightChild[pre]);
            }
        }

        return visited.size() == n;
    }
};
// @lc code=end
