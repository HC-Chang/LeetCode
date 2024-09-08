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
// Solution 2:

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        ListNode *cur;
        vector<ListNode *> arr;
        for (cur = head; cur; cur = cur->next)
            arr.push_back(cur);

        int n = arr.size();
        int q = n / k;
        int r = n % k;

        vector<ListNode *> ans;
        if (n <= k)
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(arr[i]);
                arr[i]->next = nullptr;
            }
            for (int i = 0; i < k - n; i++)
                ans.push_back({});
            return ans;
        }

        int idx = 0;
        int last = 0;
        for (int i = 0; i < k; i++)
        {
            if (i <= r - 1)
                last = min(idx + q, n - 1);
            else
                last = min(idx + q - 1, n - 1);
            ans.push_back(arr[idx]);
            arr[last]->next = nullptr;
            idx = last + 1;
        }

        return ans;
    }
};
// @lc code=end

// Note: link-list

// Solution 1:

// class Solution
// {
// public:
//     vector<ListNode *> splitListToParts(ListNode *head, int k)
//     {
//         ListNode *cur;
//         int len = 0;
//         for (cur = head; cur; cur = cur->next)
//             ++len;
//         vector<ListNode *> ans;
//         cur = head;
//         int l = len / k;
//         int r = len % k;
//         ListNode *prev = NULL;
//         for (int i = 0; i < k; ++i, --r)
//         {
//             ans.push_back(cur);
//             for (int j = 0; j < l + (r > 0); ++j)
//             {
//                 prev = cur;
//                 cur = cur->next;
//             }
//             if (prev)
//                 prev->next = NULL;
//         }
//         return ans;
//     }
// };