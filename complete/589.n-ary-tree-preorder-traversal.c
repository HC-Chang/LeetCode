/*
 * @lc app=leetcode id=589 lang=c
 *
 * [589] N-ary Tree Preorder Traversal
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

void arr_append(int *arr, int *arr_index, int val)
{
    arr[*arr_index] = val;
    *arr_index += 1;
}

void pre(struct Node *p, int *arr, int *arr_index)
{
    if (!p)
        return;
    int num = p->numChildren;
    int i;
    arr_append(arr, arr_index, p->val);
    if (num > 0)
    {
        for (i = 0; i < num; i++)
        {
            pre(p->children[i], arr, arr_index);
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorder(struct Node *root, int *returnSize)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }

    int *arr = calloc(100000, sizeof(int));
    int arr_index = 0;

    pre(root, arr, &arr_index);
    *returnSize = arr_index;

    return arr;
}
// @lc code=end
