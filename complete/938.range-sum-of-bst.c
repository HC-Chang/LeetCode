/*
 * @lc app=leetcode id=938 lang=c
 *
 * [938] Range Sum of BST
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
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if(!root)
        return 0;
    if(root->val > high)
        return rangeSumBST(root->left, low, high);
    else if(root->val < low)
        return rangeSumBST(root->right, low, high);
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}
// @lc code=end

// Note: BST

// Solution 1:
// void traveler(struct TreeNode* root, int low, int high, int *sum){
//     if(!root)
//         return 0;
//     if(root->val >= low && root->val <= high)
//         *sum += root->val;
//     if(root->left)
//             traveler(root->left, low,  high, sum);
//     if(root->right)
//             traveler(root->right, low,  high, sum);
// }

// int rangeSumBST(struct TreeNode* root, int low, int high){
//     int sum = 0;
//     traveler( root,  low,  high, &sum);
//     return sum;
// }