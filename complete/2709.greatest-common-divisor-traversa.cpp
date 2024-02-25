/*
 * @lc app=leetcode id=2709 lang=cpp
 *
 * [2709] Greatest Common Divisor Traversal
 */

// @lc code=start
class Solution
{
public:
    typedef struct
    {
        int count;
        int *parent;
        unsigned int *size;
    } UNION;

    UNION *union_find_init(int n)
    {
        UNION *obj = (UNION *)malloc(sizeof(UNION));
        obj->count = n;
        obj->parent = (int *)malloc(n * sizeof(int));
        obj->size = (unsigned int *)malloc(n * sizeof(unsigned int));
        for (int i = 0; i < n; i++)
        {
            obj->parent[i] = i;
            obj->size[i] = 1;
        }
        return obj;
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

    bool is_connected(int p, int q, UNION *u)
    {
        int root_p = find(p, u);
        int root_q = find(q, u);
        return root_p == root_q;
    }

    void union_free(UNION *u)
    {
        free(u->parent);
        free(u->size);
        free(u);
    }

    vector<int> create_primes(int n)
    {
        vector<int> primes;
        int q[n + 1];
        memset(q, 0, sizeof(q));
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (q[i] == 1)
                continue;
            int j = i * 2;
            while (j <= n)
            {
                q[j] = 1;
                j += i;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (q[i] == 0)
                primes.push_back(i);
        }
        return primes;
    }

    bool canTraverseAllPairs(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int MX = nums[N - 1];
        UNION *u = union_find_init(2 * 100005);

        vector<int> primes = create_primes(MX);
        int M = primes.size();
        int idx[MX + 1];
        for (int j = 0; j < M; j++)
            idx[primes[j]] = j;

        for (int i = 0; i < N; i++)
        {
            int x = nums[i];
            for (int j = 0; j < M; j++)
            {
                int p = primes[j];
                if (p > x)
                    break;
                if (p * p > x)
                {
                    if (!is_connected(i, N + idx[x], u))
                        union_p_q(i, N + idx[x], u);
                    break;
                }

                if (x % p == 0)
                {
                    if (!is_connected(i, N + j, u))
                        union_p_q(i, N + j, u);
                    while (x % p == 0)
                        x /= p;
                }
            }
        }

        for (int i = 1; i < N; i++)
        {
            if (!is_connected(0, i, u))
            {
                union_free(u);
                return false;
            }
        }
        union_free(u);
        return true;
    }
};
// @lc code=end

// Note: math + union find