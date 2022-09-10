/*
 * @lc app=leetcode id=160 lang=c
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }

    struct ListNode *startA = headA;
    struct ListNode *startB = headB;

    while (startA != startB)
    {
        startA = startA == NULL ? headB : startA->next;
        startB = startB == NULL ? headA : startB->next;
    }

    return startA;
}
// @lc code=end

// Linked List Cycle - 變形
// A 走完後換走 B
// B 走完後換走 A