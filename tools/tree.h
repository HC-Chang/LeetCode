/**
 * @file file
 * @author author
 * @date date
 * @brief brief
 */
#ifndef _TREE_
#define _TREE_
/*
 * NOTE Define
 */
/*
 * NOTE Type
 */
typedef struct
{
    int val;
    struct NODE *p_left;
    struct NODE *p_right;
} NODE;
/*
 * NOTE Global Variable
 */
/*
 * NOTE Function
 */
void set_node_value(NODE *p, int val);
void set_node_child(NODE *p, NODE *p_l, NODE *p_r);
void new_node(NODE *p[], int count);
void print_node(NODE *p);
void print_nodes(NODE *p[], int count);
void free_node(NODE *p);
void free_nodes(NODE *p[], int count);
// Traversal
void Preorder_Traversal(NODE *p);
void Inorder_Traversal(NODE *p);
void Postorder_Traversal(NODE *p);
void Level_order_Traversal(NODE *p);

#endif
