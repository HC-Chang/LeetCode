/*
 * @lc app=leetcode id=839 lang=c
 *
 * [839] Similar String Groups
 */

// @lc code=start
typedef struct
{
    int count;
    int *parent;
    unsigned int *size;
} UNION;

UNION *union_find_init(int n)
{
    UNION *u = malloc(sizeof(UNION));
    u->count = n;
    u->parent = malloc(n * sizeof(int));
    u->size = malloc(n * sizeof(unsigned int));
    for (int i = 0; i < n; i++)
    {
        u->parent[i] = i;
        u->size[i] = 1;
    }
    return u;
}

void union_p_q(int p, int q, UNION *u)
{
    int root_p = find(p, u);
    int root_q = find(q, u);
    if (root_p == root_q)
        return;
    if (u->size[root_p] > u->size[root_q])
    {
        u->parent[root_q] = root_p;
        u->size[root_p] += u->size[root_q];
    }
    else
    {
        u->parent[root_p] = root_q;
        u->size[root_q] += u->size[root_p];
    }
    u->count--;
}

int find(int x, UNION *u)
{
    while (u->parent[x] != x)
    {
        u->parent[x] = u->parent[u->parent[x]];
        x = u->parent[x];
    }
    return x;
}

int union_count(UNION *u)
{
    return u->count;
}

void union_free(UNION *u)
{
    free(u->parent);
    free(u->size);
    free(u);
}

bool similar(char *s1, char *s2)
{
    int count = 0;
    int s1_len = strlen(s1);
    for (int i = 0; i < s1_len; ++i)
    {
        if ((count += (s1[i] != s2[i])) > 2)
            return false;
    }

    return count == 2 || count == 0;
}

int numSimilarGroups(char **strs, int strsSize)
{
    UNION *u = union_find_init(strsSize);
    for (int i = 0; i < strsSize; ++i)
    {
        for (int j = i + 1; j < strsSize; ++j)
        {
            if (similar(strs[i], strs[j]))
                union_p_q(i, j, u);
        }
    }

    int group_count = union_count(u);
    union_free(u);
    return group_count;
}
// @lc code=end
