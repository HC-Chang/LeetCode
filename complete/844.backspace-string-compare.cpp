/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s_stack;
        stack<char> t_stack;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                if (!s_stack.empty())
                    s_stack.pop();
            }
            else
                s_stack.push(s[i]);
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#')
            {
                if (!t_stack.empty())
                    t_stack.pop();
            }
            else
                t_stack.push(t[i]);
        }

        if (s_stack.size() != t_stack.size())
            return false;

        int n = s_stack.size();
        for (int i = 0; i < n; i++)
        {
            if (s_stack.top() != t_stack.top())
                return false;
            s_stack.pop();
            t_stack.pop();
        }

        return true;
    }
};
// @lc code=end
