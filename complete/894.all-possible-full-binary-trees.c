/*
 * @lc app=leetcode id=894 lang=c
 *
 * [894] All Possible Full Binary Trees
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode *init_node()
{
    struct TreeNode *node;
    node = calloc(1, sizeof(struct TreeNode));
    return node;
}

struct TreeNode **allPossibleFBT(int n, int *returnSize)
{
    *returnSize = 0;
    if (n % 2 == 0)
        return NULL;

    struct TreeNode ***NodeList = malloc(sizeof(struct TreeNode **) * (n + 1));
    int *num = calloc((n + 1), sizeof(int));

    NodeList[1] = malloc(sizeof(struct TreeNode *));
    NodeList[1][0] = init_node();
    num[1] = 1;

    int right;
    struct TreeNode *node;
    for (int i = 3; i <= n; i += 2)
    {
        NodeList[i] = malloc(sizeof(struct TreeNode *) * 100000);
        for (int left = 1; left < i; left += 2)
        {
            right = i - 1 - left;
            for (int k = 0; k < num[left]; k++)
                for (int j = 0; j < num[right]; j++)
                {
                    node = init_node();
                    node->left = NodeList[left][k];
                    node->right = NodeList[right][j];
                    NodeList[i][num[i]] = node;
                    num[i]++;
                }
        }
    }
    *returnSize = num[n];
    return NodeList[n];
}
// @lc code=end
