#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#define NODE_SIZE 6
int main(int argc, char *argv[])
{
    NODE *node_root = calloc(1, sizeof(NODE));
    NODE *node_arr[NODE_SIZE];
    new_node(node_arr, NODE_SIZE);
    print_nodes(node_arr, NODE_SIZE);
    int parent_index = 0;
    int child_index = 0;
    set_node_child(node_root, node_arr[child_index], node_arr[child_index + 1]);
    child_index += 2;
    set_node_child(node_arr[parent_index], node_arr[child_index], node_arr[child_index + 1]);
    parent_index += 1;
    child_index += 2;
    set_node_child(node_arr[parent_index], node_arr[child_index], node_arr[child_index + 1]);
    parent_index += 1;
    child_index += 2;
    // NOTE Test
    // Preorder_Traversal(node_root);
    // Inorder_Traversal(node_root);
    // Postorder_Traversal(node_root);
    // Level_order_Traversal(node_root);
    // print_node(node_arr[1]);
    free_nodes(node_arr, NODE_SIZE);
    return 0;
}
