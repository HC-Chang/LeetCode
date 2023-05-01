/*
 * @lc app=leetcode id=83 lang=c
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *last = head;
    struct ListNode *current = head->next;
    while (current)
    {
        if (current->val == last->val)
        {
            last->next = current->next;
            free(current);
            current = last->next;
        }
        else
        {
            last = current;
            current = current->next;
        }
    }
    return head;
}
// @lc code=end
