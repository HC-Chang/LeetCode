/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        for (auto c : s)
        {
            if (!st.empty() && c == ')' && st.top() == '(')
                st.pop();
            else
                st.push(c);
        }
        return st.size();
    }
};
// @lc code=end

// Note: stack