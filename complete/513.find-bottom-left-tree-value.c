/*
 * @lc app=leetcode id=513 lang=c
 *
 * [513] Find Bottom Left Tree Value
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
typedef struct
{
    int capacity;
    int push_index;
    int pop_index;
    struct TreeNode **arr;
} QUEUE;

QUEUE *init_queue(int n)
{
    QUEUE *q = malloc(sizeof(QUEUE));
    q->capacity = n;
    q->push_index = 0;
    q->pop_index = 0;
    q->arr = calloc(n, sizeof(struct TreeNode *));
    return q;
}

void push_queue(struct TreeNode *input, QUEUE *q)
{
    q->arr[q->push_index++] = input;
}

struct TreeNode *pop_queue(QUEUE *q)
{
    return q->arr[q->pop_index++];
}

int size_queue(QUEUE *q)
{
    return q->push_index - q->pop_index;
}

void free_queue(QUEUE *q)
{
    free(q->arr);
    free(q);
}

int findBottomLeftValue(struct TreeNode *root)
{
    QUEUE *q = init_queue(10000);
    push_queue(root, q);
    struct TreeNode *node;
    while (size_queue(q))
    {
        node = pop_queue(q);
        if (node->right != NULL)
            push_queue(node->right, q);
        if (node->left != NULL)
            push_queue(node->left, q);
    }
    int r = node->val;
    free_queue(q);
    return r;
}
// @lc code=end

// Note: queue