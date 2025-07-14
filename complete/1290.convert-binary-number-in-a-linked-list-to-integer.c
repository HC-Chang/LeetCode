/*
 * @lc app=leetcode id=1290 lang=c
 *
 * [1290] Convert Binary Number in a Linked List to Integer
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode *head)
{
    int val = 0;
    while (head != NULL)
    {
        val = (val << 1) + head->val;
        head = head->next;
    }

    return val;
}
// @lc code=end

// Note: linked list + math + bit manipulation