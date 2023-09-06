/*
 * @lc app=leetcode id=725 lang=c
 *
 * [725] Split Linked List in Parts
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode **splitListToParts(struct ListNode *head, int k, int *returnSize)
{
    int len = 0;
    struct ListNode *cur;
    for (cur = head; cur; cur = cur->next)
        ++len;
    struct ListNode **ans = malloc(k * sizeof(struct ListNode *));

    cur = head;
    int l = len / k;
    int r = len % k;
    struct ListNode *prev = NULL;
    for (int i = 0; i < k; ++i, --r)
    {
        ans[i] = cur;
        for (int j = 0; j < l + (r > 0); ++j)
        {
            prev = cur;
            cur = cur->next;
        }
        if (prev)
            prev->next = NULL;
    }
    *returnSize = k;
    return ans;
}
// @lc code=end

// Note: link-list
