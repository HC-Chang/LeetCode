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

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast->next)
            fast = fast->next;
    }
    
    if (slow->next)
    {
        fast = slow->next;
        slow->val = slow->next->val;
        if (slow->next->next)
            slow->next = slow->next->next;
        else
            slow->next = NULL;
        free(fast);
    }
    else
        head->next = NULL;

    return head;
}
// @lc code=end
