/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        ListNode *cur;
        int len = 0;
        for (cur = head; cur; cur = cur->next)
            ++len;
        vector<ListNode *> ans;
        cur = head;
        int l = len / k;
        int r = len % k;
        ListNode *prev = NULL;
        for (int i = 0; i < k; ++i, --r)
        {
            ans.push_back(cur);
            for (int j = 0; j < l + (r > 0); ++j)
            {
                prev = cur;
                cur = cur->next;
            }
            if (prev)
                prev->next = NULL;
        }
        return ans;
    }
};
// @lc code=end

// Note: link-list
