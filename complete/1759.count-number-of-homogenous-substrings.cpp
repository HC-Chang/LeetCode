/*
 * @lc app=leetcode id=1759 lang=cpp
 *
 * [1759] Count Number of Homogenous Substrings
 */

// @lc code=start
class Solution
{
public:
    int countHomogenous(string s)
    {
        long long sum = 1;
        int count = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                ++count;
            else
                count = 1;
            sum += count;
        }

        return sum % (1000000007);
    }
};
// @lc code=end
