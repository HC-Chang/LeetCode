/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y)
             { return to_string(x) + to_string(y) > to_string(y) + to_string(x); });
        if (nums[0] == 0)
            return "0";

        string ans;
        for (int &n : nums)
            ans += to_string(n);

        return ans;
    }
};
// @lc code=end

// Note: greedy + sorting