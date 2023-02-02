/*
 * @lc app=leetcode id=844 lang=c
 *
 * [844] Backspace String Compare
 */

// @lc code=start

// Solution 2: stack
typedef struct
{
    int index;
    char *c;
} STACK;

void init_stack(int n, STACK *s)
{
    s->c = calloc(n, sizeof(char));
}

void free_stack(STACK *s)
{
    free(s->c);
    free(s);
}

void push_stack(char input, STACK *s)
{
    if (input == '#')
    {
        if (s->index > 0)
            --s->index;
    }
    else
        s->c[s->index++] = input;
}

bool backspaceCompare(char *s, char *t)
{
    STACK *s_stack = calloc(1, sizeof(STACK));
    STACK *t_stack = calloc(1, sizeof(STACK));
    int s_len = strlen(s);
    int t_len = strlen(t);

    init_stack(s_len, s_stack);
    init_stack(t_len, t_stack);

    for (int i = 0; i < s_len; i++)
        push_stack(s[i], s_stack);
    for (int i = 0; i < t_len; i++)
        push_stack(t[i], t_stack);

    if (s_stack->index != t_stack->index)
        return false;
    for (int i = 0; i < s_stack->index; i++)
    {
        if (s_stack->c[i] != t_stack->c[i])
            return false;
    }
    
    free_stack(s_stack);
    free_stack(t_stack);

    return true;
}
// @lc code=end

// Solution 1: double pointer
// char *m_str(char *s)
// {
//     int read = 0;
//     int write = 0;
//     while (s[read] != '\0')
//     {
//         if (s[read] != '#')
//         {
//             s[write] = s[read];
//             write++;
//         }
//         else
//         {
//             // read++;
//             if (write > 0)
//             {
//                 write--;
//             }
//         }
//         read++;
//     }

//     s[write] = '\0';

//     return s;
// }

// bool backspaceCompare(char *s, char *t)
// {
//     s = m_str(s);
//     t = m_str(t);
//     return strcmp(s, t) == 0;
// }