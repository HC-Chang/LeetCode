/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        int n = nums.size();
        int sum = nums[0];
        hash[sum] = 0;
        int tmp;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] % k == 0 && nums[i - 1] % k == 0 || (nums[i] + nums[i - 1]) % k == 0)
                return true;
            if (nums[i] % k == 0)
                continue;
            sum += nums[i];
            tmp = sum % k;
            if (!tmp)
                return true;
            if (hash.find(tmp) != hash.end() && hash[tmp] != i)
                return true;
            hash[tmp] = i;
        }
        return false;
    }
};
// @lc code=end

// Note: prefix sum + hash