/*
 * @lc app=leetcode id=25 lang=c
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    int n = 0;
    struct ListNode *cur = head;

    while (cur)
    {
        n++;
        cur = cur->next;
    }

    struct ListNode *dummy = calloc(1, sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode *p0 = dummy;
    struct ListNode *pre;
    struct ListNode *nxt;
    while (n >= k)
    {
        n -= k;
        pre = NULL;
        cur = p0->next;

        for (int i = 0; i < k; i++)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        nxt = p0->next;
        p0->next->next = cur;
        p0->next = pre;
        p0 = nxt;
    }
    return dummy->next;
}
// @lc code=end
