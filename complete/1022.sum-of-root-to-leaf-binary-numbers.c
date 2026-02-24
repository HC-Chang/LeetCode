/*
 * @lc app=leetcode id=1022 lang=c
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
void traverse(struct TreeNode *root, int *idx, char *s, int *sum)
{
    if (!root)
        return;

    s[(*idx)++] = root->val + '0';
    traverse(root->left, idx, s, sum);
    traverse(root->right, idx, s, sum);
    if (!root->left && !root->right)
    {
        s[*idx] = '\0';
        *sum += strtol(s, NULL, 2);
    }
    s[--(*idx)] = '\0';
}

int sumRootToLeaf(struct TreeNode *root)
{
    int sum = 0;
    char s[1001] = "";
    int idx = 0;
    traverse(root, &idx, s, &sum);
    return sum;
}
// @lc code=end

// Note: backtracking