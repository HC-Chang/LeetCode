/*
 * @lc app=leetcode id=445 lang=c
 *
 * [445] Add Two Numbers II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int len_list(struct ListNode *head)
{
    int cnt = 0;
    while (head)
    {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void swap_list(struct ListNode **l1, struct ListNode **l2)
{
    struct ListNode *tmp = l1[0];
    l1[0] = l2[0];
    l2[0] = tmp;
}

struct ListNode *new_ListNode(int val)
{
    struct ListNode *obj = calloc(1, sizeof(struct ListNode));
    obj->val = val;
    return obj;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int n1 = len_list(l1);
    int n2 = len_list(l2);
    int diff = abs(n1 - n2);
    if (n1 < n2)
        swap_list(&l1, &l2);
    struct ListNode *dummy = new_ListNode(0), *cur = dummy, *right = cur;
    while (diff > 0)
    {
        cur->next = new_ListNode(l1->val);
        if (l1->val != 9)
            right = cur->next;
        cur = cur->next;
        l1 = l1->next;
        --diff;
    }
    while (l1)
    {
        int val = l1->val + l2->val;
        if (val > 9)
        {
            val %= 10;
            ++(right->val);
            while (right->next)
            {
                right->next->val = 0;
                right = right->next;
            }
            right = cur;
        }
        cur->next = new_ListNode(val);
        if (val != 9)
            right = cur->next;
        cur = cur->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    return (dummy->val == 1) ? dummy : dummy->next;
}
// @lc code=end
