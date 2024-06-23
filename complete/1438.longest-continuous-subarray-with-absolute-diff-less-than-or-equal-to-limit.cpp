/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        multiset<int> s;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int max_len = 0;
        while (right < n)
        {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > limit)
            {
                s.erase(s.find(nums[left++]));
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};
// @lc code=end

// Note: sliding window

// Official Solution