/*
 * @lc app=leetcode id=2816 lang=cpp
 *
 * [2816] Double a Number Represented as a Linked List
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

    ListNode *doubleIt(ListNode *head)
    {
        head = reverse(head);
        ListNode *cur = head;
        int val_tmp = 0;
        while (cur->next)
        {
            cur->val *= 2;
            cur->val += val_tmp;
            val_tmp = 0;
            if (cur->val >= 10)
            {
                val_tmp = 1;
                cur->val -= 10;
            }
            cur = cur->next;
        }

        cur->val *= 2;
        cur->val += val_tmp;
        val_tmp = 0;
        if (cur->val >= 10)
        {
            val_tmp = 1;
            cur->val -= 10;
        }

        if (val_tmp)
        {
            ListNode *tmp = new ListNode();
            tmp->val = 1;
            tmp->next = 0;
            cur->next = tmp;
            cur = cur->next;
        }

        return reverse(head);
    }
};
// @lc code=end

// Note: linked list + stack