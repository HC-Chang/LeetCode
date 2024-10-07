/*
 * @lc app=leetcode id=2696 lang=c
 *
 * [2696] Minimum String Length After Removing Substrings
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
void push_stack(char val, STACK *obj) { obj->arr[(obj->idx)++] = val; }
void pop_stack(STACK *obj) { --obj->idx; }
char top_stack(STACK *obj) { return obj->arr[obj->idx - 1]; }
bool is_empty_stack(STACK *obj) { return obj->idx <= 0; }
void free_stack(STACK *obj)
{
    free(obj->arr);
    free(obj);
}

int minLength(char *s)
{
    int n = strlen(s);
    STACK *obj = init_stack(n);

    for (int i = 0; i < n; i++)
    {
        if (!is_empty_stack(obj) && ((top_stack(obj) == 'A' && s[i] == 'B') ||
                                     (top_stack(obj) == 'C' && s[i] == 'D')))
            pop_stack(obj);
        else
            push_stack(s[i], obj);
    }

    int cnt = obj->idx;
    free_stack(obj);

    return cnt;
}
// @lc code=end

// Note: stack
