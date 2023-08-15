/*
 * @lc app=leetcode id=86 lang=c
 *
 * [86] Partition List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *partition(struct ListNode *head, int x)
{
    if (!head)
        return NULL;
    struct ListNode *left = malloc(sizeof(struct ListNode));
    struct ListNode *right = malloc(sizeof(struct ListNode));
    struct ListNode *l_head = left;
    struct ListNode *r_head = right;
    while (head != NULL)
    {
        if (head->val < x)
        {
            left->next = head;
            left = head;
        }
        else
        {
            right->next = head;
            right = head;
        }
        head = head->next;
    }

    right->next = NULL;
    left->next = r_head->next;

    return l_head->next;
}
// @lc code=end

// Note: linked list . two pointer