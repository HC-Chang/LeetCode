/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int res = 0;
        long sum = 0;
        int left = 0;
        int right = 0;
        sort(nums.begin(), nums.end());
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum + k < (long)nums[right] * (right - left + 1))
            {
                sum -= nums[left];
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
// @lc code=end
