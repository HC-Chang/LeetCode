/*
 * @lc app=leetcode id=82 lang=c
 *
 * [82] Remove Duplicates from Sorted List II
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
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode *cur = dummy;
    struct ListNode *del;
    int val;
    while (cur->next && cur->next->next)
    {
        val = cur->next->val;
        if (cur->next->next->val == val)
        {
            while (cur->next && cur->next->val == val)
            {
                del = cur->next;
                cur->next = cur->next->next;
                free(del);
            }
        }
        else
            cur = cur->next;
    }

    return dummy->next;
}
// @lc code=end
