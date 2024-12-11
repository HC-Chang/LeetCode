/*
 * @lc app=leetcode id=2779 lang=cpp
 *
 * [2779] Maximum Beauty of an Array After Applying Operation
 */

// @lc code=start
class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        if (nums.size() == 1)
            return 1;

        int max_val = 0;
        for (auto n : nums)
            max_val = max(max_val, n);

        vector<int> count(max_val + 1, 0);

        for (auto n : nums)
        {
            count[max(n - k, 0)]++;
            if (n + k + 1 <= max_val)
                count[n + k + 1]--;
        }

        int max_beauty = 0;
        int cur_sum = 0;
        for (auto c : count)
        {
            cur_sum += c;
            max_beauty = max(max_beauty, cur_sum);
        }

        return max_beauty;
    }
};
// @lc code=end

// Note: sorting + sliding window

// Official Solution