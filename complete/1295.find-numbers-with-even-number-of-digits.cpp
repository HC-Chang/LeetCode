/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int cnt = 0;
        for (auto n : nums)
        {
            int tmp_cnt = 0;
            while (n)
            {
                n /= 10;
                ++tmp_cnt;
            }
            if (tmp_cnt % 2 == 0)
                cnt++;
        }

        return cnt;
    }
};
// @lc code=end
