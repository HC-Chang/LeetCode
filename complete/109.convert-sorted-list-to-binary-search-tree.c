/*
 * @lc app=leetcode id=109 lang=c
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedListToBST(struct ListNode *head)
{
    if (!head)
        return NULL;
    if (!head->next)
    {
        struct TreeNode *r = calloc(1, sizeof(struct TreeNode));
        r->val = head->val;

        return r;
    }

    struct ListNode *fast = head->next->next;
    struct ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    struct TreeNode *r = calloc(1, sizeof(struct TreeNode));
    r->val = slow->next->val;
    struct ListNode *righthalf = slow->next->next;
    slow->next = NULL;
    r->left = sortedListToBST(head);
    r->right = sortedListToBST(righthalf);

    return r;
}
// @lc code=end
