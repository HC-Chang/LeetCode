/*
 * @lc app=leetcode id=173 lang=c
 *
 * [173] Binary Search Tree Iterator
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
#define MAX_ARR_SIZE 1e5

typedef struct
{
    int size;
    int *arr;
    int index;
} BSTIterator;

void inorder_traverse(struct TreeNode *root, BSTIterator *obj)
{
    if (!root)
        return;
    if (root->left)
        inorder_traverse(root->left, obj);
    obj->arr[obj->size++] = root->val;
    if (root->right)
        inorder_traverse(root->right, obj);
}

BSTIterator *bSTIteratorCreate(struct TreeNode *root)
{
    BSTIterator *obj = malloc(sizeof(BSTIterator));
    obj->size = 0;
    obj->index = 0;
    obj->arr = calloc(MAX_ARR_SIZE, sizeof(int));
    inorder_traverse(root, obj);
    return obj;
}

int bSTIteratorNext(BSTIterator *obj)
{
    return obj->arr[obj->index++];
}

bool bSTIteratorHasNext(BSTIterator *obj)
{
    if (obj->index == obj->size)
        return false;
    return true;
}

void bSTIteratorFree(BSTIterator *obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/
// @lc code=end
