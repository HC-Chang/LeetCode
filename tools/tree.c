#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int val = 1;
void set_node_value(NODE *p, int val)
{
    p->val = val;
}
void set_node_child(NODE *p, NODE *p_l, NODE *p_r)
{
    p->p_left = (struct NODE *)p_l;
    p->p_right = (struct NODE *)p_r;
}
void new_node(NODE *p[], int count)
{
    for (int i = 0; i < count; i++)
    {
        p[i] = calloc(1, sizeof(NODE));
        p[i]->val = val;
        val++;
    }
}
void print_node(NODE *p)
{
    printf("%i\r\n", p->val);
}
void print_nodes(NODE *p[], int count)
{
    for (int i = 0; i < count; i++)
    {
        print_node(p[i]);
    }
}
void free_node(NODE *p)
{
    free(p);
}
void free_nodes(NODE *p[], int count)
{
    for (int i = 0; i < count; i++)
    {
        free(p[i]);
    }
}
#pragma region Traversal
// 前序遍歷 (Preorder Traversal)
// Depth-first Search
void Preorder_Traversal(NODE *p)
{
    if (!p)
    {
        return;
    }
    printf("%i\r\n", p->val);
    Preorder_Traversal((NODE *)p->p_left);
    Preorder_Traversal((NODE *)p->p_right);
}
// 中序遍歷 (Inorder Traversal)
// Depth-first Search
void Inorder_Traversal(NODE *p)
{
    if (!p)
    {
        return;
    }
    Inorder_Traversal((NODE *)p->p_left);
    printf("%i\r\n", p->val);
    Inorder_Traversal((NODE *)p->p_right);
}
// 後序遍歷 (Postorder Traversal)
// Depth-first Search
void Postorder_Traversal(NODE *p)
{
    if (!p)
    {
        return;
    }
    Postorder_Traversal((NODE *)p->p_left);
    Postorder_Traversal((NODE *)p->p_right);
    printf("%i\r\n", p->val);
}
// 層序遍歷 (Level-order Traversal)
// Breadth-first Search
void Level_order_Traversal(NODE *p)
{
    if (p != NULL)
    {
        // printf("%i\r\n",p->val);
    }
    NODE *pp;
    if ((NODE *)p->p_left != NULL)
    {
        pp = (NODE *)p->p_left;
        printf("%i\r\n", *pp);
    }
    if ((NODE *)p->p_right != NULL)
    {
        pp = (NODE *)p->p_right;
        printf("%i\r\n", *pp);
    }
    if ((NODE *)p->p_left != NULL)
    {
        pp = (NODE *)p->p_left;
        Level_order_Traversal(pp);
    }
    if ((NODE *)p->p_right != NULL)
    {
        pp = (NODE *)p->p_right;
        Level_order_Traversal(pp);
    }
}
#pragma endregion Traversal
