/*
 * @lc app=leetcode id=234 lang=c
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *left;
bool post_traverse(struct ListNode *right)
{
    if (!right)
    {
        return true;
    }

    bool result = post_traverse(right->next) && (right->val == left->val);
    left = left->next;
    return result;
}

bool isPalindrome(struct ListNode *head)
{
    left = head;
    return post_traverse(left);
}
// @lc code=end
// 後序走訪至最後 node
// 再與 head node 做比較
// l1 == r1, l2 == r2, ...
