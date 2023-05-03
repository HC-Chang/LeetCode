/*
 * @lc app=leetcode id=701 lang=c
 *
 * [701] Insert into a Binary Search Tree
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
void insert(struct TreeNode* insert_node, struct TreeNode* root, int val)
{
    if(val < root->val)
    {
        if(root->left)
            insert(insert_node, root->left, val);
        else
            root->left = insert_node;  
    }
    else if(val > root->val)
    {
        if(root->right)
            insert(insert_node, root->right, val);
        else
            root->right = insert_node;
    }
}
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode* insert_node = malloc(sizeof(struct TreeNode));
    insert_node->val = val;
    insert_node->left = NULL;
    insert_node->right = NULL;
    if(!root)
        return insert_node;
    insert(insert_node, root, val);
    return root;
}
// @lc code=end

