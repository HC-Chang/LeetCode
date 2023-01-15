/*
 * @lc app=leetcode id=1971 lang=c
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start

int count;
int *parent;
unsigned int *size;

void union_find_init(int n)
{
    count = n;
    parent = calloc(n, sizeof(int));
    size = calloc(n, sizeof(unsigned int));
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = i;
    }
}

void union_p_q(int p, int q)
{
    int root_p = find(p);
    int root_q = find(q);
    if (root_p == root_q)
        return;
    if (size[root_p] > size[root_q])
    {
        parent[root_q] = root_p;
        size[root_p] += size[root_q];
    }
    else
    {
        parent[root_p] = root_q;
        size[root_q] += size[root_p];
    }
    count--;
}

bool is_connected(int p, int q)
{
    int root_p = find(p);
    int root_q = find(q);
    return root_p == root_q;
}

int find(int x)
{
    while (parent[x] != x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

int union_count()
{
    return count;
}
bool validPath(int n, int **edges, int edgesSize, int *edgesColSize, int source, int destination)
{
    union_find_init(n);
    for (int i = 0; i < edgesSize; i++)
        union_p_q(edges[i][0], edges[i][1]);
    
    return is_connected(source, destination);
}
// @lc code=end
