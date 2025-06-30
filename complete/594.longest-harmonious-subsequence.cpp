/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int max_cnt = 0;
        int r = 0;
        for (int l = 0; l < n; l++)
        {
            while (r + 1 < n && nums[r + 1] - nums[l] <= 1)
                r++;
            if (nums[r] - nums[l] == 1 && r - l + 1 > max_cnt)
                max_cnt = r - l + 1;
            while (l + 1 < n && nums[l + 1] == nums[l])
                l++;
        }
        return max_cnt;
    }
};

// @lc code=end

// Note: sliding window + hash table + sorting + counting