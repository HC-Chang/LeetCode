/*
 * @lc app=leetcode id=143 lang=c
 *
 * [143] Reorder List
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
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    struct ListNode *nxt;
    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

void reorderList(struct ListNode *head)
{
    struct ListNode *mid = middleNode(head);
    struct ListNode *head2 = reverseList(mid);
    struct ListNode *nxt, *nxt2;
    while (head2->next)
    {
        nxt = head->next;
        nxt2 = head2->next;
        head->next = head2;
        head2->next = nxt;
        head = nxt;
        head2 = nxt2;
    }
}
// @lc code=end
