/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
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
            start = start->next;

        struct ListNode *ptr = start->next;

        if (ptr == head->next && ptr == NULL)
            return NULL;

        if (count - n == 0)
        {
            head = head->next;
            return head;
        }
        start->next = start->next->next;
        delete (ptr);
        ptr = 0;

        return head;
    }
};
// @lc code=end

// Note: linked list + two pointers