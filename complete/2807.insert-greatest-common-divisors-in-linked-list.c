/*
 * @lc app=leetcode id=2807 lang=c
 *
 * [2807] Insert Greatest Common Divisors in Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int gcd(int a, int b)
{
    if (a % b)
        return gcd(b, a % b);
    else
        return b;
}

struct ListNode *insertGreatestCommonDivisors(struct ListNode *head)
{
    int arr[5000];
    int arr_idx = 0;
    struct ListNode *cur = head;
    while (cur)
    {
        arr[arr_idx++] = cur->val;
        cur = cur->next;
    }
    struct ListNode *ans = malloc(sizeof(struct ListNode));
    ans->val = head->val;
    cur = ans;

    for (int i = 1; i < arr_idx; i++)
    {
        cur->next = malloc(sizeof(struct ListNode));
        cur->next->val = gcd(arr[i], arr[i - 1]);
        cur = cur->next;
        cur->next = malloc(sizeof(struct ListNode));
        cur->next->val = arr[i];
        cur = cur->next;
    }
    cur->next = NULL;
    return ans;
}
// @lc code=end

// Note: linked list + math