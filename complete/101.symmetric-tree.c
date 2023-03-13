/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Solution 2: queue

typedef struct
{
    int capacity;
    int push_index;
    int pop_index;
    struct TreeNode **arr_val;
} QUEUE;

void init_queue(int n, QUEUE *q)
{
    q->capacity = n;
    q->arr_val = calloc(n, sizeof(struct TreeNode *));
}

void push_queue(struct TreeNode *input, QUEUE *q)
{
    q->arr_val[q->push_index++] = input;
}

struct TreeNode *pop_queue(QUEUE *q)
{
    return q->arr_val[q->pop_index++];
}

int is_empty_queue(QUEUE *q)
{
    return q->push_index == q->pop_index;
}

void free_queue(QUEUE *q)
{
    free(q->arr_val);
    free(q);
}

bool isSymmetric(struct TreeNode *root)
{
    if (!root)
        return true;
    QUEUE *q = calloc(1, sizeof(QUEUE));
    init_queue(1000, q);

    push_queue(root, q);
    push_queue(root, q);

    struct TreeNode *a;
    struct TreeNode *b;

    while (!is_empty_queue(q))
    {
        a = pop_queue(q);
        b = pop_queue(q);
        if (!a && !b)
            continue;
        if (!a || !b || a->val != b->val)
            return false;
        push_queue(a->left, q);
        push_queue(b->right, q);
        push_queue(a->right, q);
        push_queue(b->left, q);
    }
    free_queue(q);
    return true;
}
// @lc code=end

// Solution 1:

// bool is_symmetric(struct TreeNode *r1, struct TreeNode *r2)
// {
//     return (!r1 && !r2) || (r1 && r2 && r1->val == r2->val && is_symmetric(r1->left, r2->right) && is_symmetric(r1->right, r2->left));
// }

// bool isSymmetric(struct TreeNode *root)
// {
//     return is_symmetric(root, root);
// }