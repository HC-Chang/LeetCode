/*
 * @lc app=leetcode id=24 lang=c
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *swapPairs(struct ListNode *head)
{
    if (!head || !head->next)
        return head;

    struct ListNode *node = head->next;

    head->next = swapPairs(head->next->next);
    node->next = head;

    return node;
}
// @lc code=end
