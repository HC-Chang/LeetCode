/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto &c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else if (!st.empty())
            {
                if ((c == ')' && st.top() == '(') ||
                    (c == ']' && st.top() == '[') ||
                    (c == '}' && st.top() == '{'))
                    st.pop();
                else
                    break;
            }
            else
                return false;
        }

        return st.empty();
    }
};
// @lc code=end

// Note: stack
