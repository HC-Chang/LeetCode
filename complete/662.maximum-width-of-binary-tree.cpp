/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    vector<vector<unsigned long long>> v;
    unsigned long long ans = 0;
    void dfs(TreeNode *node, int lv, unsigned long long nodeId)
    {
        if (!node)
            return;
        if (v.size() <= lv)
            v.push_back({ULLONG_MAX, 0});
        v[lv][0] = min(v[lv][0], nodeId);
        v[lv][1] = max(v[lv][1], nodeId);
        ans = max(ans, v[lv][1] - v[lv][0] + 1);
        dfs(node->left, lv + 1, 2 * nodeId);
        dfs(node->right, lv + 1, 2 * nodeId + 1);
    }

public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root, 0, 0);
        return ans;
    }
};
// @lc code=end
