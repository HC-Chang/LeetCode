/*
 * @lc app=leetcode id=124 lang=c
 *
 * [124] Binary Tree Maximum Path Sum
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
int maxx(int a, int b) { return a > b ? a : b; }
int max_sum(struct TreeNode *root, int *max)
{
    if (!root)
        return 0;
    int l_max = INT_MIN, r_max = INT_MIN;
    int l_sub_max = max_sum(root->left, &l_max);
    int r_sub_max = max_sum(root->right, &r_max);

    int tmp_max = root->val + maxx(l_sub_max, 0) + maxx(r_sub_max, 0);
    tmp_max = maxx(maxx(l_max, r_max), tmp_max);
    *max = tmp_max;

    if (l_sub_max < 0 && r_sub_max < 0)
        return root->val;
    else
        return root->val + maxx(l_sub_max, r_sub_max);
}

int maxPathSum(struct TreeNode *root)
{
    int max = 0;
    max_sum(root, &max);
    return max;
}
// @lc code=end
