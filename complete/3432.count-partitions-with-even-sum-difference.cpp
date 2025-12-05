/*
 * @lc app=leetcode id=3432 lang=cpp
 *
 * [3432] Count Partitions with Even Sum Difference
 */

// @lc code=start
class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];

        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if ((nums[n - 1] - 2 * nums[i]) % 2 == 0)
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end

// Note: math + prefix sum