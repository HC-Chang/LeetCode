/*
 * @lc app=leetcode id=653 lang=c
 *
 * [653] Two Sum IV - Input is a BST
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
int node_count(struct TreeNode *root)
{
    if (NULL == root)
        return 0;
    return node_count(root->left) + node_count(root->right) + 1;
}

void bst2arr(struct TreeNode *root, int *arr, int *index)
{
    if (!root)
        return;
    if (root->left)
        bst2arr(root->left, arr, index);

    arr[(*index)++] = root->val;

    if (root->right)
        bst2arr(root->right, arr, index);
}

bool findTarget(struct TreeNode *root, int k)
{
    int count = node_count(root);
    int *arr = calloc(count, sizeof(int));
    int index = 0;

    bst2arr(root, arr, &index);

    int small = 0;
    int big = count - 1;
    while (small < big)
    {
        if (k - arr[big] == arr[small])
            return true;
        else if (k - arr[big] < arr[small])
            big--;
        else
            small++;
    }
    free(arr);
    return false;
}
// @lc code=end

// Convert BST to array
// Search 2 sum in array 