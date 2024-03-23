/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    ListNode *reverseList(struct ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *nxt;
        while (cur)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    ListNode *middleNode(struct ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow;
    }
    void reorderList(ListNode *head)
    {
        ListNode *mid = middleNode(head);
        ListNode *head2 = reverseList(mid);
        ListNode *nxt, *nxt2;
        while (head2->next)
        {
            nxt = head->next;
            nxt2 = head2->next;
            head->next = head2;
            head2->next = nxt;
            head = nxt;
            head2 = nxt2;
        }
    }
};
// @lc code=end

// Note: linked list + two pointers