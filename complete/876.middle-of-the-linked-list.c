/*
 * @lc app=leetcode id=876 lang=c
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 單向鏈結陣列 (Singly-Linked List)
struct ListNode *middleNode(struct ListNode *head)
{
    // Solution 1
    // struct ListNode *temp = head;

    // int length = 0;
    // while (temp != NULL)
    // {
    //     temp = temp->next;
    //     length++;
    // }

    // temp = head;
    // for (int i = 0; i < length / 2; i++)
    // {
    //     temp = temp->next;
    // }

    // return temp;

    // Solution 2 - 快慢指標
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}
// @lc code=end

// Note: linked list + two pointers