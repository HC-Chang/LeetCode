/*
 * @lc app=leetcode id=2469 lang=cpp
 *
 * [2469] Convert the Temperature
 */

// @lc code=start
class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        vector<double> ans;
        ans.push_back(celsius + 273.15);
        ans.push_back(celsius * 1.80 + 32.00);

        return ans;
    }
};
// @lc code=end
