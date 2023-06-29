/*
 * @lc app=leetcode id=92 lang=c
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    struct ListNode *dummy = calloc(1, sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *p0 = dummy;

    for (int i = 0; i < left - 1; i++)
        p0 = p0->next;

    struct ListNode *pre = NULL;
    struct ListNode *cur = p0->next;
    struct ListNode *nxt;
    for (int i = 0; i < right - left + 1; i++)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    p0->next->next = cur;
    p0->next = pre;
    return dummy->next;
}
// @lc code=end
