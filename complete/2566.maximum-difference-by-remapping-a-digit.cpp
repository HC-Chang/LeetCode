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
        string s1 = to_string(num);
        string s2 = s1;
        size_t pos = s1.find_first_not_of('9');
        if (pos != string::npos)
        {
            char c1 = s1[pos];
            replace(s1.begin(), s1.end(), c1, '9');
        }
        char c2 = s2[0];
        replace(s2.begin(), s2.end(), c2, '0');
        return stoi(s1) - stoi(s2);
    }
};
// @lc code=end

// Note: math + greedy