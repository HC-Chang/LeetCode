/*
 * @lc app=leetcode id=108 lang=c
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
struct TreeNode *create_bst(int *nums, int left, int right)
{
    if (left < 0 || left > right)
        return NULL;
    int mid = left + (right - left) / 2;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = create_bst(nums, left, mid - 1);
    node->right = create_bst(nums, mid + 1, right);
    return node;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    return create_bst(nums, 0, numsSize - 1);
}
// @lc code=end
