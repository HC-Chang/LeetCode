/*
 * @lc app=leetcode id=2709 lang=c
 *
 * [2709] Greatest Common Divisor Traversal
 */

// @lc code=start
#define PRIMES_SIZE 10000

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

int sort(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int *create_primes(int n, int *prime_size)
{
    int *primes = malloc(PRIMES_SIZE * sizeof(int));
    *prime_size = 0;
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
            primes[(*prime_size)++] = i;
    }
    return primes;
}

bool canTraverseAllPairs(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);

    int MX = nums[numsSize - 1];
    UNION *u = union_find_init(2 * 100005);

    int M = 0;
    int *primes = create_primes(MX, &M);
    int N = numsSize;
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
    free(primes);
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
// @lc code=end

// Note: math + union find