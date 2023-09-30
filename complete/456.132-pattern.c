/*
 * @lc app=leetcode id=456 lang=c
 *
 * [456] 132 Pattern
 */

// @lc code=start
typedef struct
{
    int capacity;
    int idx;
    int *arr;
} STACK;

STACK *init_stack(int n)
{
    STACK *obj = malloc(sizeof(STACK));
    obj->capacity = n;
    obj->idx = 0;
    obj->arr = calloc(n, sizeof(int));
    return obj;
}

void push_stack(int val, STACK *obj)
{
    obj->arr[obj->idx++] = val;
}

void pop_stack(STACK *obj)
{
    obj->idx--;
}

int top_stack(STACK *obj)
{
    return obj->arr[obj->idx - 1];
}

bool is_empty_stack(STACK *obj)
{
    return obj->idx <= 0;
}

void free_stack(STACK *obj)
{
    free(obj->arr);
    free(obj);
}

bool find132pattern(int *nums, int numsSize)
{
    int third = INT_MIN;
    STACK *stack = init_stack(numsSize);
    for (int i = numsSize - 1; i >= 0; --i)
    {
        if (nums[i] < third)
        {
            free_stack(stack);
            return true;
        }

        while (!is_empty_stack(stack) && nums[i] > top_stack(stack))
        {
            third = top_stack(stack);
            pop_stack(stack);
        }

        push_stack(nums[i], stack);
    }

    free_stack(stack);
    return false;
}
// @lc code=end
