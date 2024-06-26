/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> inorderSeq;

    void getInorder(TreeNode *o)
    {
        if (o->left)
            getInorder(o->left);
        inorderSeq.push_back(o->val);
        if (o->right)
            getInorder(o->right);
    }

    TreeNode *build(int l, int r)
    {
        int mid = (l + r) >> 1;
        TreeNode *o = new TreeNode(inorderSeq[mid]);
        if (l <= mid - 1)
            o->left = build(l, mid - 1);
        if (mid + 1 <= r)
            o->right = build(mid + 1, r);
        return o;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        getInorder(root);
        return build(0, inorderSeq.size() - 1);
    }
};

// @lc code=end

// Note: DFS + binary search

// Official Solution