/*
 * @lc app=leetcode id=2918 lang=c
 *
 * [2918] Minimum Equal Sum of Two Arrays After Replacing Zeros
 */

// @lc code=start
class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long sum1{0};
        long long sum2{0};
        int z_cnt1{0};
        int z_cnt2{0};
        for (auto n : nums1)
        {
            if (n == 0)
                ++z_cnt1;
            else
                sum1 += n;
        }
        for (auto n : nums2)
        {
            if (n == 0)
                ++z_cnt2;
            else
                sum2 += n;
        }

        if ((z_cnt1 == 0 && sum2 + z_cnt2 > sum1) || (z_cnt2 == 0 && sum1 + z_cnt1 > sum2))
            return -1;

        return max(sum1 + z_cnt1, sum2 + z_cnt2);
    }
};
// @lc code=end

// Note: greedy