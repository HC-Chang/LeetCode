/*
 * @lc app=leetcode id=2566 lang=cpp
 *
 * [2566] Maximum Difference by Remapping a Digit
 */

// @lc code=start
class Solution
{
public:
    int minMaxDifference(int num)
    {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos)
        {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        char b = t[0];
        replace(t.begin(), t.end(), b, '0');
        return stoi(s) - stoi(t);
    }
};
// @lc code=end

// Note: math + greedy