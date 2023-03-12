/*
 * @lc app=leetcode id=23 lang=c
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Solution 2: 
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    if (list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;

    for (int i = 1; i < listsSize; i++)
        lists[0] = mergeTwoLists(lists[0], lists[i]);

    return lists[0];
}
// @lc code=end

// Solution 1:

// struct ListNode *merge(struct ListNode **lists, int listsSize)
// {
//     int not_null = 0;
//     int min = INT_MAX;
//     int min_index;
//     for (int i = 0; i < listsSize; i++)
//     {
//         not_null |= (lists[i] != NULL);
//         if (lists[i] == NULL)
//             continue;
//         if (min > lists[i]->val)
//         {
//             min = lists[i]->val;
//             min_index = i;
//         }
//     }
//     if (!not_null || min == INT_MAX)
//         return NULL;

//     struct ListNode *node = calloc(1, sizeof(struct ListNode));
//     node->val = min;
//     lists[min_index] = lists[min_index]->next;
//     return node;
// }

// struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
// {
//     if (listsSize == 0)
//         return NULL;
//     if (listsSize == 1)
//         return lists[0];

//     struct ListNode *r = calloc(1, sizeof(struct ListNode));
//     struct ListNode *node = r;
//     while (node)
//     {
//         node->next = merge(lists, listsSize);
//         node = node->next;
//     }
//     return r->next;
// }