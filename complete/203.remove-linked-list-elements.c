/*
 * @lc app=leetcode id=203 lang=c
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeElements(struct ListNode *head, int val)
{
    if (!head)
        return NULL;

    struct ListNode *prev = NULL;
    struct ListNode *remove = head;

    while (remove)
    {
        if (remove->val != val)
            break;
        head = remove->next;
        free(remove);
        remove = head;
    }

    while (remove)
    {
        if (remove->val == val)
        {
            prev->next = remove->next;
            free(remove);
            remove = prev;
        }
        prev = remove;
        remove = remove->next;
    }

    return head;
}
// @lc code=end
