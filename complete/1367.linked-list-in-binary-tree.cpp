/*
 * @lc app=leetcode id=1367 lang=cpp
 *
 * [1367] Linked List in Binary Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        vector<int> pattern = {head->val}, prefixTable = {0};
        int patternIndex = 0;
        head = head->next;

        while (head)
        {
            while (patternIndex && head->val != pattern[patternIndex])
                patternIndex = prefixTable[patternIndex - 1];
            patternIndex += head->val == pattern[patternIndex];
            pattern.push_back(head->val);
            prefixTable.push_back(patternIndex);
            head = head->next;
        }

        return dfs(root, 0, pattern, prefixTable);
    }

private:
    bool dfs(TreeNode *node, int patternIndex,
             const vector<int> &pattern,
             const vector<int> &prefixTable)
    {
        if (!node)
            return false;

        while (patternIndex && node->val != pattern[patternIndex])
            patternIndex = prefixTable[patternIndex - 1];
        patternIndex += node->val == pattern[patternIndex];

        if (patternIndex == pattern.size())
            return true;

        return dfs(node->left, patternIndex, pattern, prefixTable) ||
               dfs(node->right, patternIndex, pattern, prefixTable);
    }
};
// @lc code=end

// Note: linked list + DFS

// Official Solution