/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        if (n == 1)
            return stoi(tokens[0]);

        vector<int> stack(n);
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (tokens[i].size() == 1)
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
                    stack[index++] = stoi(tokens[i]);
                    break;
                }
            }
            else
                stack[index++] = stoi(tokens[i]);
        }
        return stack[index - 1];
    }
};
// @lc code=end

// Note: stack