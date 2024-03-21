/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Solution 2:
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    struct ListNode *nxt;
    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
// @lc code=end

// Note: linked list

// Solution 1:

// struct ListNode* reverseList(struct ListNode* head){
//     if(!head || !head->next)
//         return head;
//     struct ListNode* last = reverseList(head->next);
//     head->next->next= head;
//     head->next= NULL;
//     return last;
// }