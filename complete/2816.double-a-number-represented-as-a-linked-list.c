/*
 * @lc app=leetcode id=2816 lang=c
 *
 * [2816] Double a Number Represented as a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *current = NULL;
    struct ListNode *temp = head;
    struct ListNode *tempnext;
    while (temp != NULL)
    {
        tempnext = temp->next;
        temp->next = current;
        current = temp;
        temp = tempnext;
    }
    head = current;
    return head;
}

struct ListNode *doubleIt(struct ListNode *head)
{
    head = reverse(head);
    struct ListNode *cur = head;
    int val_tmp = 0;
    while (cur->next)
    {
        cur->val *= 2;
        cur->val += val_tmp;
        val_tmp = 0;
        if (cur->val >= 10)
        {
            val_tmp = 1;
            cur->val -= 10;
        }
        cur = cur->next;
    }

    cur->val *= 2;
    cur->val += val_tmp;
    val_tmp = 0;
    if (cur->val >= 10)
    {
        val_tmp = 1;
        cur->val -= 10;
    }

    if (val_tmp)
    {
        struct ListNode *tmp = malloc(sizeof(struct ListNode));
        tmp->val = 1;
        tmp->next = 0;
        cur->next = tmp;
        cur = cur->next;
    }

    return reverse(head);
}
// @lc code=end

// Note: linked list + stack