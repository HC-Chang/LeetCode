/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
class Solution
{
public:
    bool checkValidString(string s)
    {
        if (s[0] == ')')
            return false;

        int min_count = 0;
        int max_count = 0;
        for (auto c : s)
        {
            switch (c)
            {
            case '(':
                min_count++;
                max_count++;
                break;
            case ')':
                min_count--;
                max_count--;
                break;
            case '*':
                min_count--;
                max_count++;
                break;
            }

            if (max_count < 0)
                return false;
            if (min_count < 0)
                min_count = 0;
        }

        return min_count == 0;
    }
};
// @lc code=end

// NOTE '*' 可當左括弧、右括弧、空白