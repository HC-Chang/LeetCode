/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode dummy(0, head);
        int prefix = 0;
        unordered_map<int, ListNode *> hash;
        hash[0] = &dummy;

        for (; head; head = head->next)
        {
            prefix += head->val;
            hash[prefix] = head;
        }

        prefix = 0;
        for (head = &dummy; head; head = head->next)
        {
            prefix += head->val;
            head->next = hash[prefix]->next;
        }

        return dummy.next;
    }
};
// @lc code=end

// Note: hash table + linded list