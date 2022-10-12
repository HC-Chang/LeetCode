/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */

// @lc code=start

bool isValid(char *s)
{
    char *stack = calloc(strlen(s), sizeof(char));
    int index = 0;
    while (*s)
    {
        switch (*s)
        {
        case '(':
            stack[index++] = *s + 1;
            break;
        case '[':
        case '{':
            stack[index++] = *s + 2;
            break;
        case ')':
        case ']':
        case '}':
            if (index - 1 < 0)
            {
                return false;
            }
            if (stack[index - 1] != *s)
            {
                return false;
            }
            index--;
            break;
        default:
            break;
        }
        s++;
    }

    free(stack);

    return index == 0;
}
// @lc code=end
