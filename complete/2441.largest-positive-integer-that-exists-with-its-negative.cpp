/*
 * @lc app=leetcode id=2441 lang=cpp
 *
 * [2441] Largest Positive Integer That Exists With Its Negative
 */

// @lc code=start
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int visited[2001] = {0};
        int ans = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ++(visited[nums[i] + 1000]);
            if (visited[nums[i] + 1000] && visited[-nums[i] + 1000] && abs(nums[i]) > ans)
                ans = abs(nums[i]);
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table / sorting + two pointers