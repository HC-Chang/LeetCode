/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        long long diff;
        int contribution;
        int ans = 0;
        vector<unordered_map<long long, int>> counts(nums.size());
        for (int i = 1; i != nums.size(); ++i)
            for (int j = 0; j < i; ++j)
            {
                contribution = 0;
                diff = (long long)nums[i] - nums[j];
                if (counts[j].find(diff) != counts[j].end())
                    contribution = counts[j][diff];
                counts[i][diff] += contribution + 1;
                ans += contribution;
            }
        return ans;
    }
};
// @lc code=end

// Note: hash map + DP