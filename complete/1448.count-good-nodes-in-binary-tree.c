/*
 * @lc app=leetcode id=1448 lang=c
 *
 * [1448] Count Good Nodes in Binary Tree
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

// Solution 2:
void count_good(int *count, int max_val, struct TreeNode *root)
{
    if (!root)
        return;

    if (root->val >= max_val)
    {
        max_val = root->val;
        ++*count;
    }
    if (root->left)
        count_good(count, max_val, root->left);
    if (root->right)
        count_good(count, max_val, root->right);
}

int goodNodes(struct TreeNode *root)
{
    int count = 0;
    int max_val = INT_MIN;
    count_good(&count, max_val, root);
    return count;
}
// @lc code=end

// Solution 1:
// void count_good(int *count, struct TreeNode* last, struct TreeNode* root)
// {
//     if(!root)
//         return;
// 
//     if(root->val >= last->val)
//     {
//         last = root;
//         ++*count;
//     }
//     if(root->left)
//         count_good(count, last, root->left);
//     if(root->right)
//         count_good(count, last, root->right);
// }
// 
// int goodNodes(struct TreeNode* root){
//     int count =1;
//     struct TreeNode* last =  NULL;
//     count_good(&count, root, root->left);
//     count_good(&count, root, root->right);
//     return count;
// }