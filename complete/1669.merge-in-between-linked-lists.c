/*
 * @lc app=leetcode id=1669 lang=c
 *
 * [1669] Merge In Between Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeInBetween(struct ListNode *list1, int a, int b, struct ListNode *list2)
{
    struct ListNode *prev = NULL;
    struct ListNode *cur = list1;
    struct ListNode *next = list1->next;
    while (cur->next)
    {
        if (--a == 0)
            prev = cur;
        cur = cur->next;
        next = next->next;
        if (--b == 0)
            break;
    }

    prev->next = list2;
    cur = list2;
    while (cur->next)
        cur = cur->next;
    cur->next = next;

    return list1;
}
// @lc code=end

// Note: linked list