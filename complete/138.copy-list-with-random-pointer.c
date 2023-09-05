/*
 * @lc app=leetcode id=138 lang=c
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node *new_node(int val)
{
    struct Node *obj = calloc(1, sizeof(struct Node));
    obj->val = val;
    return obj;
}

struct Node *copyRandomList(struct Node *head)
{
    if (!head)
        return NULL;
    struct Node *cur = head;
    struct Node *t;
    while (cur)
    {
        t = new_node(cur->val);
        t->next = cur->next;
        cur->next = t;
        cur = t->next;
    }

    cur = head;
    while (cur)
    {
        if (cur->random)
            cur->next->random = cur->random->next;
        cur = cur->next->next;
    }

    cur = head;
    struct Node *res = head->next;
    while (cur)
    {
        t = cur->next;
        cur->next = t->next;
        if (t->next)
            t->next = t->next->next;
        cur = cur->next;
    }
    return res;
}
// @lc code=end

// Note: hash table + linked list