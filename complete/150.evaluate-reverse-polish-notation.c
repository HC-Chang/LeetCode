/*
 * @lc app=leetcode id=150 lang=c
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
int evalRPN(char **tokens, int tokensSize)
{
    if (tokensSize == 1)
        return atoi(tokens[0]);
    int *stack = calloc(10000, sizeof(int));
    int index = 0;
    for (int i = 0; i < tokensSize; i++)
    {
        if (strlen(tokens[i]) == 1)
        {
            switch (tokens[i][0])
            {
            case '+':
                stack[index - 2] += stack[index - 1];
                index--;
                break;
            case '-':
                stack[index - 2] -= stack[index - 1];
                index--;
                break;
            case '*':
                stack[index - 2] = (int)((long)stack[index - 2] * stack[index - 1]);
                index--;
                break;
            case '/':
                if (stack[index - 1] != 0)
                    stack[index - 2] /= stack[index - 1];
                index--;
                break;
            default:
                stack[index++] = atoi(tokens[i]);
                break;
            }
        }
        else
            stack[index++] = atoi(tokens[i]);
    }
    int ans = stack[index - 1];
    free(stack);
    return ans;
}
// @lc code=end
