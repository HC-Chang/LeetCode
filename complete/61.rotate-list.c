/*
 * @lc app=leetcode id=61 lang=c
 *
 * [61] Rotate List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int ListCount(struct ListNode *head)
{
    int count = 1;
    while (head)
    {
        if (head->next != NULL)
        {
            head = head->next;
            count++;
        }
        else
        {
            head = NULL;
        }
    }

    return count;
}

struct ListNode *TargetNode(struct ListNode *head, int index)
{
    for (int i = 0; i < index; i++)
    {
        head = head->next;
    }
    return head;
}

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    int count = ListCount(head);
    k %= count;

    if (k == 0)
    {
        return head;
    }

    // make ring pointer
    struct ListNode *OriginBottom = TargetNode(head, count - 1);
    OriginBottom->next = head;

    struct ListNode *NewHead = TargetNode(head, count - k);

    struct ListNode *NewBottom = TargetNode(head, count - k - 1);
    NewBottom->next = NULL;

    return NewHead;
}
// @lc code=end
