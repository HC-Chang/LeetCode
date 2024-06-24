/*
 * @lc app=leetcode id=995 lang=cpp
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 */

// @lc code=start
class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int cnt = 0;
        int flipped = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (i >= k)
                flipped -= nums[i - k] / 2;
            if (flipped % 2 == nums[i])
            {
                if (i + k > n)
                    return -1;
                nums[i] += 2;
                ++flipped;
                ++cnt;
            }
        }
        return cnt;
    }
};
// @lc code=end
