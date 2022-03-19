/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *NewList(void)
{
    return calloc(1, sizeof(struct ListNode));
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *start = calloc(1, sizeof(struct ListNode));
    struct ListNode *sum = start;

    int add_index = 0;
    int ll1 = 0;
    int ll2 = 0;
    int count = 0;
    while (l1 || l2 || add_index)
    {
        if (count == 0)
        {
            count = 1;
        }
        else
        {
            sum->next = NewList();
            sum = sum->next;
        }

        // 進位
        if (add_index == 1)
        {
            sum->val = 1;
            add_index = 0;
        }

        // if (l1)
        // {
        //     ll1 = l1->val;
        // }
        // else
        // {
        //     ll1 = 0;
        // }
        ll1 = l1 ? l1->val : 0;

        // if (l2)
        // {
        //     ll2 = l2->val;
        // }
        // else
        // {
        //     ll2 = 0;
        // }
        ll2 = l2 ? l2->val : 0;

        sum->val += ll1 + ll2;

        // 檢查進位
        if (sum->val > 9)
        {
            add_index = sum->val / 10;
            sum->val %= 10;
        }

        // if (l1 && l1->next)
        // {
        //     l1 = l1->next;
        // }
        // else
        // {
        //     l1 = NULL;
        // }
        l1 = (l1 && l1->next)?l1->next :NULL;

        // if (l2 && l2->next)
        // {
        //     l2 = l2->next;
        // }
        // else
        // {
        //     l2 = NULL;
        // }
        l2 = (l2 && l2->next)?l2->next :NULL;
    }

    return start;
}
// @lc code=end
