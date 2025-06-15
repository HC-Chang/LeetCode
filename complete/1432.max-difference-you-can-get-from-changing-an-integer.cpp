/*
 * @lc app=leetcode id=1432 lang=cpp
 *
 * [1432] Max Difference You Can Get From Changing an Integer
 */

// @lc code=start
class Solution
{
public:
    int maxDiff(int num)
    {
        auto replace = [](string &s, char x, char y)
        {
            for (char &digit : s)
            {
                if (digit == x)
                {
                    digit = y;
                }
            }
        };

        string s1 = to_string(num);
        string s2 = to_string(num);
        for (char digit : s2)
        {
            if (digit != '9')
            {
                replace(s2, digit, '9');
                break;
            }
        }

        for (int i = 0; i < s1.size(); ++i)
        {
            char digit = s1[i];
            if (i == 0)
            {
                if (digit != '1')
                {
                    replace(s1, digit, '1');
                    break;
                }
            }
            else
            {
                if (digit != '0' && digit != s1[0])
                {
                    replace(s1, digit, '0');
                    break;
                }
            }
        }

        return stoi(s2) - stoi(s1);
    }
};
// @lc code=end

// Note: math + greedy

// Official Solution