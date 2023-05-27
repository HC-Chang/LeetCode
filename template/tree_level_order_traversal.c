int height(struct TreeNode *root)
{
    if (!root)
        return 0;
    int l_height = height(root->left) + 1;
    int r_height = height(root->right) + 1;
    return l_height > r_height ? l_height : r_height;
}

int **traverse(struct TreeNode *root, int **r, int level, int *col)
{
    if (!root)
        return r;

    r[level] = realloc(r[level], (col[level] + 1) * sizeof(int));
    r[level][col[level]] = root->val;
    col[level] += 1;
    traverse(root->left, r, level + 1, col);
    traverse(root->right, r, level + 1, col);
    return r;
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = height(root);
    returnColumnSizes[0] = calloc((*returnSize), sizeof(int));

    int **r = malloc(*returnSize * sizeof(int *));
    for (int i = 0; i < *returnSize; i++)
        r[i] = malloc(sizeof(int));

    traverse(root, r, 0, returnColumnSizes[0]);

    return r;
}