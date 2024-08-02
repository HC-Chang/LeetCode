/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int minimumSwaps = INT_MAX;
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        int onesCount = nums[0];
        int end = 0;

        for (int start = 0; start < nums.size(); ++start)
        {
            if (start != 0)
                onesCount -= nums[start - 1];

            while (end - start + 1 < totalOnes)
            {
                end++;
                onesCount += nums[end % nums.size()];
            }

            minimumSwaps = min(minimumSwaps, totalOnes - onesCount);
        }

        return minimumSwaps;
    }
};
// @lc code=end

// Note: sliding window

// Official Solution