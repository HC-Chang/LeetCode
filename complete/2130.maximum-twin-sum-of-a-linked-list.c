/*
 * @lc app=leetcode id=2130 lang=c
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode *head)
{
    struct ListNode *fast = head->next, *slow = head;
    int *arr = calloc(1e5, sizeof(int));
    int index = 0;
    arr[index++] = slow->val;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        arr[index++] = slow->val;
    }
    int max_sum = INT_MIN;
    int sum;
    while (slow->next)
    {
        slow = slow->next;
        sum = arr[--index] + slow->val;
        if (sum > max_sum)
            max_sum = sum;
    }
    free(arr);
    return max_sum;
}
// @lc code=end
