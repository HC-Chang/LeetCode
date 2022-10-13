/*
 * @lc app=leetcode id=237 lang=c
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode *node)
{
    struct ListNode *delete_node = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    free(delete_node);
}
// @lc code=end
