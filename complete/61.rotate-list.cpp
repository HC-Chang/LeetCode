/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
            return head;
        vector<ListNode *> v;
        ListNode *cur = head;
        int n = 0;
        while (cur != nullptr)
        {
            v.push_back(cur);
            n++;
            cur = cur->next;
        }

        k %= n;
        if (k == 0)
            return head;

        v[n - 1]->next = head;
        v[n - k - 1]->next = nullptr;
        head = v[n - k];

        return head;
    }
};
// @lc code=end
