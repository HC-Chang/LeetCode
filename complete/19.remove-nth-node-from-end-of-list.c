/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *start = head;
    int count = 1;
    while (start->next)
    {
        start = start->next;
        count++;
    }

    start = head;
    for (int i = 0; i < count - n - 1; i++)
    {
        start = start->next;
    }
    struct ListNode *ptr = start->next;
    
    // if free only head
    if (ptr == head->next && ptr == NULL)
    {
        return NULL;
    }

    // if free_ptr == head
    if (count - n == 0)
    {
        head = head->next;
        return head;
    }
    start->next = start->next->next;
    free(ptr);

    return head;
}
// @lc code=end

// Note: linked list + two pointers