/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *current = NULL;
        ListNode *temp = head;
        ListNode *tempnext;
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

    ListNode *removeNodes(ListNode *head)
    {
        head = reverse(head);
        int mock = 0;
        ListNode *temp = head;
        ListNode *current = head;
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
};
// @lc code=end

// Note: linked list + monotonic stack
