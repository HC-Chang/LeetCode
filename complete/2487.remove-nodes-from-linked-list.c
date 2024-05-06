/*
 * @lc app=leetcode id=2487 lang=c
 *
 * [2487] Remove Nodes From Linked List
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

struct ListNode *removeNodes(struct ListNode *head)
{
    head = reverse(head);
    int mock = 0;
    struct ListNode *temp = head;
    struct ListNode *current = head;
    while (temp != NULL)
    {
        if (mock <= temp->val)
        {
            mock = temp->val;
            current = temp;
        }
        else
            current->next = temp->next;
        temp = temp->next;
    }
    head = reverse(head);
    return head;
}
// @lc code=end

// Note: linked list + monotonic stack

// Solution 1:

// struct ListNode* removeNodes(struct ListNode* head) {
//     int arr[100000] = {0};
//     int idx = 0;
//     struct ListNode* cur = head;
//     while(cur)
//     {
//         while(idx>0 && cur->val >arr[idx-1])
//             idx--;
//         arr[idx++] = cur->val;
//         cur = cur->next;
//     }
//
//     cur = head;
//     for(int i = 0 ;i<idx-1; i++)
//     {
//         cur->val = arr[i];
//         cur = cur->next;
//     }
//     cur->val = arr[idx-1];
//     cur->next = NULL;
//     return head;
// }