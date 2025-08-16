/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution
{
public:
    int maximum69Number(int num)
    {
        string val = to_string(num);
        int n = val.size();
        for (int i = 0; i < n; i++)
        {
            if (val[i] == '6')
            {
                val[i] = '9';
                break;
            }
        }
        return atoi(val.c_str());
    }
};
// @lc code=end

// Note: greedy