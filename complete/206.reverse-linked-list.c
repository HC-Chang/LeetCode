/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *last = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return last;
}
// @lc code=end
