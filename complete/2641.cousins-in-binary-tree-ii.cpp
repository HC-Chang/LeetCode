/*
 * @lc app=leetcode id=2641 lang=cpp
 *
 * [2641] Cousins in Binary Tree II
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;

        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        int previousLevelSum = root->val;

        while (!nodeQueue.empty())
        {
            int levelSize = nodeQueue.size();
            int currentLevelSum = 0;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = nodeQueue.front();
                nodeQueue.pop();
                currentNode->val = previousLevelSum - currentNode->val;

                int siblingSum =
                    (currentNode->left != nullptr ? currentNode->left->val
                                                  : 0) +
                    (currentNode->right != nullptr ? currentNode->right->val
                                                   : 0);

                if (currentNode->left != nullptr)
                {
                    currentLevelSum += currentNode->left->val;
                    currentNode->left->val = siblingSum;
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right != nullptr)
                {
                    currentLevelSum += currentNode->right->val;
                    currentNode->right->val = siblingSum;
                    nodeQueue.push(currentNode->right);
                }
            }

            previousLevelSum = currentLevelSum;
        }
        return root;
    }
};
// @lc code=end

// Note: hash table + DFS / BFS

// Official Solution