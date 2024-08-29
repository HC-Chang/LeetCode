/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution
{
public:
    typedef struct
    {
        int count;
        vector<int> parent;
        vector<unsigned int> size;
    } UNION;

    int find(int x, UNION *u)
    {
        while (u->parent[x] != x)
        {
            u->parent[x] = u->parent[u->parent[x]];
            x = u->parent[x];
        }
        return x;
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

    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        if (n <= 1)
            return 0;

        UNION u;
        u.count = n;
        u.parent = vector<int>(n);
        u.size = vector<unsigned int>(n);
        for (int i = 0; i < n; i++)
        {
            u.parent[i] = i;
            u.size[i] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1])
                    union_p_q(i, j, &u);
            }
        }

        return n - u.count;
    }
};
// @lc code=end

// Note: union find