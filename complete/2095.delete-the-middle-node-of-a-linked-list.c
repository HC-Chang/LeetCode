/*
 * @lc app=leetcode id=2095 lang=c
 *
 * [2095] Delete the Middle Node of a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteMiddle(struct ListNode *head)
{
    if (!head->next)
        return NULL;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *prev_slow;

    while (fast->next)
    {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast->next)
            fast = fast->next;
    }
    prev_slow->next = slow->next;
    free(slow);
    return head;
}
// @lc code=end

// Note: Linked List
