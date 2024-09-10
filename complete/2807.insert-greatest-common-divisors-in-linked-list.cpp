/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
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
    int gcd(int a, int b)
    {
        if (a % b)
            return gcd(b, a % b);
        else
            return b;
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        vector<int> arr;
        ListNode *cur = head;
        while (cur)
        {
            arr.push_back(cur->val);
            cur = cur->next;
        }
        ListNode *ans = new ListNode(head->val);
        cur = ans;
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            cur->next = new ListNode(gcd(arr[i], arr[i - 1]));
            cur = cur->next;
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }

        return ans;
    }
};
// @lc code=end

// Note: linked list + math