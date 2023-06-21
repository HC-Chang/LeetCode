/*
 * @lc app=leetcode id=2448 lang=c
 *
 * [2448] Minimum Cost to Make Array Equal
 */

// @lc code=start
typedef struct
{
    int num;
    int index;
} DATA;

int sort(void *a, void *b)
{
    DATA *x = (DATA *)a;
    DATA *y = (DATA *)b;

    return x->num - y->num;
}

long long minCost(int *nums, int numsSize, int *cost, int costSize)
{
    DATA d[1000000] = {0};
    long long sum_cost = 0, sum = 0, ans = 0;

    for (int i = 0; i < numsSize; i++)
    {
        d[i].num = nums[i];
        d[i].index = i;
        sum_cost += cost[i];
    }
    qsort(d, numsSize, sizeof(DATA), sort);

    if (sum_cost & 1)
        sum_cost = sum_cost + 1 >> 1;
    else
        sum_cost = sum_cost >> 1;

    int i;
    for (i = 0; i < numsSize; i++)
    {
        sum += cost[d[i].index];
        if (sum >= sum_cost)
            break;
    }

    int mid = d[i].num;
    for (i = 0; i < numsSize; i++)
        ans += abs(nums[i] - mid) * 1LL * cost[i];

    return ans;
}
// @lc code=end
