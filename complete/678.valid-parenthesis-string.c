/*
 * @lc app=leetcode id=678 lang=c
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
bool checkValidString(char *s)
{
    if (s[0] == ')')
    {
        return false;
    }

    int min_count = 0;
    int max_count = 0;
    while (*s != '\0')
    {
        switch (*s)
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
        {
            return false;
        }
        if (min_count < 0)
        {
            // 可用'*'數歸零
            min_count = 0;
        }
        s++;
    }

    return min_count == 0;
}
// @lc code=end

// NOTE '*' 可當左括弧、右括弧、空白