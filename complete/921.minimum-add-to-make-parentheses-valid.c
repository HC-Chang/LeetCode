/*
 * @lc app=leetcode id=921 lang=c
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
typedef struct
{
    int capacity;
    int idx;
    char *arr;
} STACK;

STACK *init_stack(int n)
{
    STACK *obj = malloc(sizeof(STACK));
    obj->capacity = n;
    obj->idx = 0;
    obj->arr = malloc(n * sizeof(char));

    return obj;
}

void push_stack(char c, STACK *obj)
{
    obj->arr[obj->idx++] = c;
}

void pop_stack(STACK *obj)
{
    --obj->idx;
}

char top_stack(STACK *obj)
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

int minAddToMakeValid(char *s)
{
    int n = strlen(s);
    STACK *stack = init_stack(n);
    for (int i = 0; i < n; i++)
    {
        if (!is_empty_stack(stack) && s[i] == ')' && top_stack(stack) == '(')
            pop_stack(stack);
        else
            push_stack(s[i], stack);
    }

    int cnt = stack->idx;
    free_stack(stack);
    return cnt;
}
// @lc code=end

// Note: stack