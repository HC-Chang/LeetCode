/*
 * @lc app=leetcode id=3097 lang=cpp
 *
 * [3097] Shortest Subarray With OR at Least K II
 */

// @lc code=start
class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int min_len = INT_MAX;
        int l = 0;
        int r = 0;
        vector<int> bitCounts(32, 0);
        int n = nums.size();

        while (r < n)
        {
            updateBitCounts(bitCounts, nums[r], 1);

            while (l <= r && convertBitCountsToNumber(bitCounts) >= k)
            {
                min_len = min(min_len, r - l + 1);

                updateBitCounts(bitCounts, nums[l], -1);
                l++;
            }
            r++;
        }

        return min_len == INT_MAX ? -1 : min_len;
    }

private:
    void updateBitCounts(vector<int> &bitCounts, int number, int delta)
    {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++)
        {
            if ((number >> bitPosition) & 1)
                bitCounts[bitPosition] += delta;
        }
    }

    int convertBitCountsToNumber(const vector<int> &bitCounts)
    {
        int result = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++)
        {
            if (bitCounts[bitPosition] != 0)
                result |= 1 << bitPosition;
        }
        return result;
    }
};
// @lc code=end

// Note: bit manipulation + sliding window

// Official Solution