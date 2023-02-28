/*
 * @lc app=leetcode id=606 lang=c
 *
 * [606] Construct String from Binary Tree
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

char *tree2str(struct TreeNode *root)
{
    if (!root)
        return "";
    char *left = "";
    char *right = "";

    if (root->left)
        left = tree2str(root->left);
    if (root->right)
        right = tree2str(root->right);

    char *str = malloc(30000 * sizeof(char));
    sprintf(str, "%d", root->val);
    int l_len = strlen(left);
    int r_len = strlen(right);

    if (l_len || r_len)
    {
        str = strcat(str, "(");
        str = strcat(str, left);
        str = strcat(str, ")");
    }
    if (r_len)
    {
        str = strcat(str, "(");
        str = strcat(str, right);
        str = strcat(str, ")");
    }
    return str;
}
// @lc code=end
