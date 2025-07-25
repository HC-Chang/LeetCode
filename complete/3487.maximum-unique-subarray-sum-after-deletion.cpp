/*
 * @lc app=leetcode id=3487 lang=cpp
 *
 * [3487] Maximum Unique Subarray Sum After Deletion
 */

// @lc code=start
class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> hash;
        int sum = nums[0];
        hash[nums[0]]++;
        for (int i = 1; i < n; i++)
        {
            if (hash[nums[i]]++ == 0)
                sum = max(max(sum, sum + nums[i]), nums[i]);
        }

        return sum;
    }
};
// @lc code=end

// Note: hash table + greedy
