/*
 * @lc app=leetcode id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *cur = head;
        vector<int> arr;
        while (cur)
        {
            arr.push_back(cur->val);
            cur = cur->next;
        }

        int c_idx = 0;
        int n = arr.size();
        for (int i = 1; i < n - 1; i++)
        {
            if ((arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) ||
                (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]))
                arr[c_idx++] = i;
        }

        if (c_idx < 2)
            return {-1, -1};

        int min_val = INT_MAX;
        int max_val = arr[c_idx - 1] - arr[0];
        for (int i = 0; i < c_idx - 1; i++)
            min_val = min(min_val, arr[i + 1] - arr[i]);
        return {min_val, max_val};
    }
};
// @lc code=end

// Note: linked list