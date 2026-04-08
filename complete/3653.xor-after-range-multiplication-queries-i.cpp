/*
 * @lc app=leetcode id=3653 lang=cpp
 *
 * [3653] XOR After Range Multiplication Queries I
 */

// @lc code=start
class Solution
{
public:
    static const int mod = 1e9 + 7;
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        for (auto &q : queries)
        {
            for (int i = q[0]; i <= q[1]; i += q[2])
                nums[i] = 1LL * nums[i] * q[3] % mod;
        }

        for (int i = 1; i < nums.size(); i++)
            nums[i] ^= nums[i - 1];

        return *nums.rbegin();
    }
};
// @lc code=end

