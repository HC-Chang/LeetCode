/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start
class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        if (chalk[0] > k)
            return 0;
        long long sum = 0;
        for (auto c : chalk)
            sum += c;

        k %= sum;
        int n = chalk.size();
        for (int i = 0; i < n; i++)
        {
            k -= chalk[i];
            if (k < 0)
                return i;
        }
        return n - 1;
    }
};
// @lc code=end

// Note: prefix sum