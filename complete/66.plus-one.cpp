/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        int flag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            flag = 0;
            if (++digits[i] <= 9)
                break;
            else
            {
                digits[i] %= 10;
                flag = 1;
            }
        }

        if (flag)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
// @lc code=end
