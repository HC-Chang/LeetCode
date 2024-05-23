/*
 * @lc app=leetcode id=2597 lang=cpp
 *
 * [2597] The Number of Beautiful Subsets
 */

// @lc code=start
class Solution
{
public:
    int picked[1001];
    int targets[20];
    int dfs(vector<int> &numbers, int numsSize, int now)
    {
        if (now == numsSize)
            return 1;
        if (picked[targets[now]])
            return dfs(numbers, numsSize, now + 1);
        ++picked[numbers[now]];
        int buffer = dfs(numbers, numsSize, now + 1);
        --picked[numbers[now]];
        return buffer + dfs(numbers, numsSize, now + 1);
    }

    int beautifulSubsets(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i != n; ++i)
            if (nums[i] > k)
                targets[i] = nums[i] - k;
            else
                targets[i] = 0;
        return dfs(nums, n, 0) - 1;
    }
};
// @lc code=end

// Note: DP + backtracking + sorting
