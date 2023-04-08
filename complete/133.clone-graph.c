/*
 * @lc app=leetcode id=133 lang=c
 *
 * [133] Clone Graph
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node *deep_clone_node(struct Node *old, struct Node **map)
{
    if (map[old->val] != 0)
        return map[old->val];
    struct Node *new = calloc(1, sizeof(struct Node));
    map[old->val] = new;
    new->val = old->val;
    new->numNeighbors = old->numNeighbors;
    struct Node **new_neighbors = calloc(new->numNeighbors, sizeof(struct Node *));

    for (int i = 0; i < new->numNeighbors; i++)
        new_neighbors[i] = deep_clone_node(old->neighbors[i], map);
    new->neighbors = new_neighbors;
    return new;
}

struct Node *cloneGraph(struct Node *s)
{
    if (!s)
        return NULL;
    struct Node **map = calloc(101, sizeof(struct Node *));
    struct Node *r = deep_clone_node(s, map);
    free(map);
    return r;
}
// @lc code=end
