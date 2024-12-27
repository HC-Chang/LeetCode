/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int offset = INT_MIN;
        int b_value = INT_MIN;
        for (int i = n - 2; i >= 0; i--)
        {
            offset = max(values[i + 1] - i - 1, offset);
            b_value = max(values[i] + i + offset, b_value);
        }
        return b_value;
    }
};

// @lc code=end

// Note: DP