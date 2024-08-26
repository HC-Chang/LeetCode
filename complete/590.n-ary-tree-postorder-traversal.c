/*
 * @lc app=leetcode id=590 lang=c
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traverse(struct Node *root, int *arr_size, int *arr)
{
    if (!root)
        return;
    for (int i = 0; i < root->numChildren; i++)
        traverse(root->children[i], arr_size, arr);
    arr[(*arr_size)++] = root->val;
}

int *postorder(struct Node *root, int *returnSize)
{
    int *arr = malloc(10000 * sizeof(int));
    *returnSize = 0;
    traverse(root, returnSize, arr);
    return arr;
}
// @lc code=end

// Note: tree + DFS