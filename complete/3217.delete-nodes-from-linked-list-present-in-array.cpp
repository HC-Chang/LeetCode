/*
 * @lc app=leetcode id=3217 lang=cpp
 *
 * [3217] Delete Nodes From Linked List Present in Array
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_map<int, int> hash;
        for (const auto &n : nums)
            ++hash[n];
        ListNode *cur = head;
        ListNode *tmp = nullptr;
        while (cur != nullptr)
        {
            if (hash.find(cur->val) == hash.end())
            {
                if (tmp == nullptr)
                {
                    head = cur;
                    tmp = head;
                }
                else
                {
                    tmp->next = cur;
                    tmp = tmp->next;
                }
            }
            cur = cur->next;
        }
        tmp->next = nullptr;
        return head;
    }
};
// @lc code=end

// Note: link list + hash table