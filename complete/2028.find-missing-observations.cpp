/*
 * @lc app=leetcode id=2028 lang=cpp
 *
 * [2028] Find Missing Observations
 */

// @lc code=start
class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);

        int r_size = rolls.size();
        int diff = mean * (r_size + n) - sum;
        int q = diff / n;
        int r = diff % n;
        if (((sum + n * 6) / (r_size + n) < mean) ||
            ((sum + n) / (r_size + n) > mean) || q == 0)
            return {};

        vector<int> arr(n, q);
        for (int i = 0; i < n; i++)
        {
            if (r-- > 0)
                arr[i]++;
            else
                break;
        }

        return arr;
    }
};
// @lc code=end

// Note: math