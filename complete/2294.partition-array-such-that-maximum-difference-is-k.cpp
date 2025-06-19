/*
 * @lc app=leetcode id=2294 lang=cpp
 *
 * [2294] Partition Array Such That Maximum Difference Is K
 */

// @lc code=start
class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int n = nums.size();
        int val = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - val > k)
            {
                val = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

// Note: greedy + sorting