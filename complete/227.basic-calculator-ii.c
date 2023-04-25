/*
 * @lc app=leetcode id=227 lang=c
 *
 * [227] Basic Calculator II
 */

// @lc code=start
typedef struct
{
    int capacity;
    int *arr;
    int index;
} STACK;

STACK *init_stack(int n)
{
    STACK *obj = malloc(sizeof(STACK));
    obj->capacity = n;
    obj->arr = calloc(n, sizeof(int));
    obj->index = 0;
    return obj;
}

void push_stack(int val, STACK *obj)
{
    obj->arr[obj->index++] = val;
}

int pop_stack(STACK *obj)
{
    return obj->arr[--obj->index];
}

void free_stack(STACK *obj)
{
    free(obj->arr);
    free(obj);
}

int calculate(char *s)
{
    int s_len = strlen(s);
    STACK *obj = init_stack(s_len);

    int index = 0;
    long sum = 0;
    char operator= '+'; // default
    int pop_number;
    while (1)
    {
        if (s[index] >= '0' && s[index] <= '9')
            sum = sum * 10 + (s[index] - '0');

        if (s[index] == '*' || s[index] == '/' || s[index] == '+' || s[index] == '-' || s[index] == '\0')
        {
            switch (operator)
            {
            case '-':
                sum *= -1;
            case '+':
                push_stack(sum, obj);
                break;
            case '*':
                pop_number = pop_stack(obj);
                push_stack(pop_number * sum, obj);
                break;
            case '/':
                pop_number = pop_stack(obj);
                push_stack(pop_number / sum, obj);
                break;
            default:
                break;
            }
            if (s[index] == '\0')
                break;

            sum = 0;
            operator= s[index];
        }
        index++;
    }

    int r = 0;
    while (obj->index > 0)
        r += pop_stack(obj);

    free_stack(obj);
    return r;
}
// @lc code=end
