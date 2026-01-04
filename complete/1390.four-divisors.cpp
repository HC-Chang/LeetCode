/*
 * @lc app=leetcode id=1390 lang=cpp
 *
 * [1390] Four Divisors
 */

// @lc code=start
class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        set<int> s;
        int sum = 0;
        int sq;
        for (const auto &n : nums)
        {
            s.clear();
            sq = sqrt(n);
            for (int i = 2; i <= sq; i++)
            {
                if (n % i == 0)
                {
                    s.insert(i);
                    s.insert(n / i);
                }
            }
            if (s.size() == 2)
                sum = accumulate(s.begin(), s.end(), sum) + 1 + n;
        }

        return sum;
    }
};
// @lc code=end

// Note: math