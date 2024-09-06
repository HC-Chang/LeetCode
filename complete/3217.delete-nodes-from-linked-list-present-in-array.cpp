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
        for (auto n : nums)
            ++hash[n];

        ListNode *ans = new ListNode();
        ListNode *cur = ans;
        while (head != nullptr)
        {
            if (!hash[head->val])
            {
                cur->next = head;
                cur = cur->next;
            }
            head = head->next;
        }
        cur->next = nullptr;

        return ans->next;
    }
};
// @lc code=end

// Note: link list + hash table