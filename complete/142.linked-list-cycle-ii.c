/*
 * @lc app=leetcode id=142 lang=c
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = fast;
    while (fast && fast->next)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast->next)
        {
            fast = fast->next;
        }
        else
        {
            break;
        }
        
        if (fast == slow)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }

            return fast;
        }
    }

    return NULL;
}
// @lc code=end
