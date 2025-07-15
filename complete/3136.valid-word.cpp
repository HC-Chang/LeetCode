/*
 * @lc app=leetcode id=3136 lang=cpp
 *
 * [3136] Valid Word
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string word)
    {
        if (word.size() < 3)
            return false;
        bool has_vow = false;
        bool has_con = false;
        for (auto c : word)
        {
            if (!isalpha(c) && !isdigit(c))
                return false;
            if (isdigit(c))
                continue;
            switch (c)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                has_vow = true;
                break;
            default:
                has_con = true;
                break;
            }
        }

        return has_vow && has_con;
    }
};
// @lc code=end
