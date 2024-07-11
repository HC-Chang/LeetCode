/*
 * @lc app=leetcode id=1190 lang=c
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
void reverse(char *ans, int str_size)
{
    char tmp;
    for (int j = 0; j < str_size / 2; j++)
    {
        tmp = ans[j];
        ans[j] = ans[str_size - j - 1], ans[str_size - j - 1] = tmp;
    }
}

char *reverseParentheses(char *s)
{
    int n = strlen(s);
    char *stack[n];
    int top = 0;
    char *ans = malloc(sizeof(char) * (n + 1));
    ans[0] = '\0';
    int str_size = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            stack[top] = malloc(sizeof(char) * (str_size + 1));
            memcpy(stack[top], ans, sizeof(char) * (str_size + 1));
            top++;
            ans[0] = '\0';
            str_size = 0;
        }
        else if (s[i] == ')')
        {
            reverse(ans, str_size);
            int len = strlen(stack[top - 1]);
            for (int j = str_size; j >= 0; j--)
            {
                ans[j + len] = ans[j];
            }
            memcpy(ans, stack[top - 1], sizeof(char) * len);
            str_size += len;
            top--;
        }
        else
        {
            ans[str_size++] = s[i];
            ans[str_size] = '\0';
        }
    }
    return ans;
}

// @lc code=end

// Note: stack

// Official Soluiton