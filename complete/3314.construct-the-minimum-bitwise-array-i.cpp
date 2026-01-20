/*
 * @lc app=leetcode id=3314 lang=cpp
 *
 * [3314] Construct the Minimum Bitwise Array I
 */

// @lc code=start
class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        for (auto &n : nums)
        {
            int tmp = -1;
            for (int i = n / 2; i < n; i++)
            {
                if ((i | (i + 1)) == n)
                {
                    tmp = i;
                    break;
                }
            }
            n = tmp;
        }
        return nums;
    }
};
// @lc code=end

// Note: bit manipulation