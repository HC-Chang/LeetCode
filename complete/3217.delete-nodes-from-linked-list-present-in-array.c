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

    struct ListNode *cur = head;
    struct ListNode *tmp = NULL;
    while (cur != NULL)
    {
        if (!hash[cur->val])
        {
            if (tmp == NULL)
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
    tmp->next = NULL;
    return head;
}
// @lc code=end

// Note: link list + hash table