/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *tmp = cur;
        while (tmp->next)
        {
            if (tmp->val == 0)
            {
                cur = cur->next;
                tmp = tmp->next;
                cur->val = tmp->val;
            }
            else
                cur->val += tmp->val;
            tmp = tmp->next;
        }
        cur->next = NULL;

        return head->next;
    }
};
// @lc code=end

// Note: linked list