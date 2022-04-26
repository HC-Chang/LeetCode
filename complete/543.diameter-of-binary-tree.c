/*
 * @lc app=leetcode id=543 lang=c
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l_depth = maxDepth(root->left);
    int r_depth = maxDepth(root->right);

    return ((l_depth > r_depth) ? l_depth : r_depth) + 1;
}

int diameterOfBinaryTree(struct TreeNode *root)
{
    // 邊界
    if (root == NULL)
    {
        return 0;
    }

    // 1.最長路徑通過樹根 (左子樹+右子樹)
    int max_root = maxDepth(root->left) + maxDepth(root->right);

    // 2.最長路徑不通過樹根
    // 2.1左邊
    int max_left = diameterOfBinaryTree(root->left);
    // 2.2右邊
    int max_right = diameterOfBinaryTree(root->right);

    int max = max_root;
    max = max > max_left ? max : max_left;
    max = max > max_right ? max : max_right;

    return max;
}
// @lc code=end
