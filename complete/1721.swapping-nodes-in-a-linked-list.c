/*
 * @lc app=leetcode id=1721 lang=c
 *
 * [1721] Swapping Nodes in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *swapNodes(struct ListNode *head, int k)
{
    int count = 1;
    int val;
    struct ListNode *node = head;
    while (node->next)
    {
        node = node->next;
        count++;
    }

    if (k == count)
    {
        val = node->val;
        node->val = head->val;
        head->val = val;
        return head;
    }

    struct ListNode *n1 = head, *n2 = head;
    int c1, c2;
    if (count - k > k - 1)
    {
        c1 = count - k;
        c2 = k - 1;
    }
    else
    {
        c1 = k - 1;
        c2 = count - k;
    }

    for (int i = 0; i < c1; i++)
    {
        if (i < c2)
            n1 = n1->next;
        n2 = n2->next;
    }

    val = n1->val;
    n1->val = n2->val;
    n2->val = val;
    return head;
}
// @lc code=end
