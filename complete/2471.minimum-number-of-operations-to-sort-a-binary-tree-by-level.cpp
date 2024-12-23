/*
 * @lc app=leetcode id=2471 lang=cpp
 *
 * [2471] Minimum Number of Operations to Sort a Binary Tree by Level
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int height(TreeNode *root, int h)
    {
        int l = 0;
        int r = 0;
        if (!root)
            return h;
        if (root->left)
            l = height(root->left, h + 1);
        if (root->right)
            r = height(root->right, h + 1);

        return max(h, max(l, r));
    }

    void traverse(TreeNode *root, int h, vector<vector<TreeNode *>> &arrs)
    {
        if (!root)
            return;

        arrs[h].push_back(root);
        if (root->left)
            traverse(root->left, h + 1, arrs);
        if (root->right)
            traverse(root->right, h + 1, arrs);
    }

    int sort_cnt(int layer, vector<vector<TreeNode *>> &arrs)
    {
        int cnt = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto a : arrs[layer])
            pq.push(a->val);

        int n = arrs[layer].size();
        for (int i = 0; i < n; i++)
        {
            if (arrs[layer][i]->val != pq.top())
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arrs[layer][j]->val == pq.top())
                    {
                        arrs[layer][j]->val = arrs[layer][i]->val;
                        break;
                    }
                }
                cnt++;
            }
            pq.pop();
        }

        return cnt;
    }

    int minimumOperations(TreeNode *root)
    {
        int h = height(root, 1);
        vector<vector<TreeNode *>> arrs(h);
        traverse(root, 0, arrs);

        int cnt = 0;
        for (int i = 1; i < h; i++)
            cnt += sort_cnt(i, arrs);
        return cnt;
    }
};
// @lc code=end

// Note: tree + BFS