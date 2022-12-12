/*
 * @lc app=leetcode id=328 lang=c
 *
 * [328] Odd Even Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head){
    if(!head)
        return NULL;
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* even_head = even;

    while(even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    
    return head;
}
// @lc code=end

