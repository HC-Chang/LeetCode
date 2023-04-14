/*
 * @lc app=leetcode id=148 lang=c
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;

NODE *middleNode(NODE *head)
{
    NODE *slow = head;
    NODE *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode *mergeList(struct ListNode *l_list, struct ListNode *r_list)
{
    if (l_list == NULL || r_list == NULL)
    {
        if (l_list == NULL && r_list == NULL)
            return NULL;
        return (r_list != NULL ? r_list : l_list);
    }

    NODE *r_node = NULL;
    if (l_list->val < r_list->val)
    {
        r_node = l_list;
        l_list = l_list->next;
    }
    else
    {
        r_node = r_list;
        r_list = r_list->next;
    }

    NODE *tmp = r_node;
    while (l_list && r_list)
    {
        if (l_list->val < r_list->val)
        {
            tmp->next = l_list;
            l_list = l_list->next;
        }
        else
        {
            tmp->next = r_list;
            r_list = r_list->next;
        }
        tmp = tmp->next;
    }

    while (l_list)
    {
        tmp->next = l_list;
        l_list = l_list->next;
        tmp = tmp->next;
    }
    while (r_list)
    {
        tmp->next = r_list;
        r_list = r_list->next;
        tmp = tmp->next;
    }

    tmp = NULL;
    return r_node;
}

struct ListNode *sortList(struct ListNode *head)
{
    if (NULL == head || NULL == head->next)
        return head;

    NODE *mid_node = middleNode(head);

    NODE *tmp = head;
    NODE *pre = NULL;
    while (tmp != mid_node)
    {
        pre = tmp;
        tmp = tmp->next;
    }
    pre->next = NULL;

    NODE *l_list = sortList(head);
    NODE *r_list = sortList(mid_node);

    return mergeList(l_list, r_list);
}
// @lc code=end
