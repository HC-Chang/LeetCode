/*
 * @lc app=leetcode id=872 lang=c
 *
 * [872] Leaf-Similar Trees
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
void last(struct TreeNode *root, int *arr, int *index)
{
    if (!root)
        return;
    if (root->left)
        last(root->left, arr, index);
    if (root->right)
        last(root->right, arr, index);
    if (!root->left && !root->right)
        arr[++*index] = root->val;
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    if (!root1 && !root2)
        return true;
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false;

    int arr1[200] = {0};
    int arr2[200] = {0};
    int index1 = 0;
    int index2 = 0;
    last(root1, arr1, &index1);
    last(root2, arr2, &index2);

    if (index1 != index2)
        return false;
    return !memcmp(arr1, arr2, 200*sizeof(int));
}
// @lc code=end
