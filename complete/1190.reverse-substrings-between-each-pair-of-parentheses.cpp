/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<string> st;
        string ans;
        for (auto &c : s)
        {
            if (c == '(')
            {
                st.push(ans);
                ans = "";
            }
            else if (c == ')')
            {
                reverse(ans.begin(), ans.end());
                ans = st.top() + ans;
                st.pop();
            }
            else
                ans.push_back(c);
        }
        return ans;
    }
};
// @lc code=end

// Note: stack

// Official Soluiton