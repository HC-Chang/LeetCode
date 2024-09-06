/*
 * @lc app=leetcode id=3217 lang=c
 *
 * [3217] Delete Nodes From Linked List Present in Array
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *modifiedList(int *nums, int numsSize, struct ListNode *head)
{
    int hash[100001] = {0};
    for (int i = 0; i < numsSize; i++)
        ++hash[nums[i]];

    struct ListNode *ans = malloc(sizeof(struct ListNode));
    struct ListNode *cur = ans;
    while (head)
    {
        if (!hash[head->val])
        {
            cur->next = head;
            cur = cur->next;
        }
        head = head->next;
    }
    cur->next = NULL;

    return ans->next;
}
// @lc code=end

// Note: link list + hash table