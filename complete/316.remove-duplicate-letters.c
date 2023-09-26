/*
 * @lc app=leetcode id=316 lang=c
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
typedef struct
{
    int capacity;
    int idx;
    char *arr;
} STACK;

STACK *init_stack(int capacity)
{
    STACK *obj = calloc(1, sizeof(STACK));
    obj->capacity = capacity;
    obj->arr = calloc(capacity, sizeof(char));
    return obj;
}

void push_stack(char val, STACK *obj)
{
    obj->arr[obj->idx++] = val;
}

void pop_stack(STACK *obj)
{
    --obj->idx;
}

char top_stack(STACK *obj)
{
    return obj->arr[obj->idx - 1];
}

int is_empty_stack(STACK *obj)
{
    return obj->idx <= 0 ? 1 : 0;
}

void free_stack(STACK *obj)
{
    free(obj->arr);
    free(obj);
}

char *removeDuplicateLetters(char *s)
{
    int selected[26] = {0};
    int count[26] = {0};
    int s_len = strlen(s);
    STACK *stack = init_stack(s_len);

    for (int i = 0; i < s_len; i++)
        ++count[s[i] - 'a'];

    for (int i = 0; i < s_len; i++)
    {
        --count[s[i] - 'a'];

        if (selected[s[i] - 'a'])
            continue;

        while (!is_empty_stack(stack) && top_stack(stack) > s[i] && count[top_stack(stack) - 'a'] > 0)
        {
            selected[top_stack(stack) - 'a'] = false;
            pop_stack(stack);
        }

        push_stack(s[i], stack);
        selected[s[i] - 'a'] = 1;
    }

    char *ans = malloc((s_len + 1) * sizeof(char));
    int idx = 0;
    while (!is_empty_stack(stack))
    {
        ans[idx++] = top_stack(stack);
        pop_stack(stack);
    }

    char tmp;
    for (int i = 0; i < idx / 2; i++)
    {
        tmp = ans[i];
        ans[i] = ans[idx - 1 - i];
        ans[idx - 1 - i] = tmp;
    }
    ans[idx] = 0;
    free_stack(stack);
    return ans;
}
// @lc code=end

// Note: stack
// This question is the same as 1081