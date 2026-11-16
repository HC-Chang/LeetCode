/*
 * @lc app=leetcode id=2243 lang=cpp
 *
 * [2243] Calculate Digit Sum of a String
 */

// @lc code=start
class Solution
{
public:
    string digitSum(string s, int k)
    {
        while (s.size() > k)
        {
            string tmp = "";
            int idx = 0;
            int val = 0;
            for (auto &c : s)
            {
                val += c - '0';
                idx++;
                if (idx % k == 0)
                {
                    tmp += to_string(val);
                    val = 0;
                }
            }
            if (idx % k != 0)
                tmp += to_string(val);
            s = tmp;
        }
        return s;
    }
};
// @lc code=end
