/*
 * @lc app=leetcode id=907 lang=c
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
typedef struct
{
    int size;
    int *arr;
    int idx;
} STACK;
STACK *init_stack(int n)
{
    STACK *obj = malloc(sizeof(STACK));
    obj->size = n;
    obj->arr = calloc(n, sizeof(int));
    obj->idx = 0;
    return obj;
}

void push_stack(int val, STACK *obj)
{
    obj->arr[obj->idx++] = val;
}

void pop_stack(STACK *obj)
{
    --obj->idx;
}

int top_stack(STACK *obj)
{
    return obj->arr[obj->idx - 1];
}

bool is_empty_stack(STACK *obj)
{
    return obj->idx == 0;
}

void free_stack(STACK *obj)
{
    free(obj->arr);
    free(obj);
}

int sumSubarrayMins(int *arr, int arrSize)
{
    int n = arrSize;
    long long ans = 0;
    long long mod = 1e9 + 7;
    STACK *monoStack = init_stack(arrSize);
    int dp[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        while (!is_empty_stack(monoStack) && arr[top_stack(monoStack)] > arr[i])
            pop_stack(monoStack);

        int k = is_empty_stack(monoStack) ? (i + 1) : (i - top_stack(monoStack));
        dp[i] = k * arr[i] + (is_empty_stack(monoStack) ? 0 : dp[i - k]);
        ans = (ans + dp[i]) % mod;
        push_stack(i, monoStack);
    }

    free_stack(monoStack);
    return ans;
}
// @lc code=end

// Note: DP + monotonic stack

// Official Solution