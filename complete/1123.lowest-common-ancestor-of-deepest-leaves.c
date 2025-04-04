/*
 * @lc app=leetcode id=1123 lang=c
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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
typedef struct
{
    struct TreeNode *ptr;
    int cnt;
} NODE;

NODE dfs(struct TreeNode *root)
{
    if (!root)
    {
        return (NODE){};
    }

    NODE l = dfs(root->left);
    NODE r = dfs(root->right);

    if (l.cnt > r.cnt)
    {
        l.cnt++;
        return l;
    }
    if (l.cnt < r.cnt)
    {
        r.cnt++;
        return r;
    }

    NODE obj;
    obj.ptr = root;
    obj.cnt = l.cnt + 1;
    return obj;
}

struct TreeNode *lcaDeepestLeaves(struct TreeNode *root)
{
    return dfs(root).ptr;
}
// @lc code=end

// Note; hash table + tree + DFS