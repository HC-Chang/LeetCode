/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *prev = NULL;
        ListNode *cur = list1;
        ListNode *next = list1->next;
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
};
// @lc code=end

// Note: linked list