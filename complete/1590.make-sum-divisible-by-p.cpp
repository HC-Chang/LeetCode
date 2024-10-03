/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        int totalSum = 0;

        for (int num : nums)
            totalSum = (totalSum + num) % p;

        int target = totalSum % p;
        if (target == 0)
            return 0;

        unordered_map<int, int> modMap;
        modMap[0] = -1;
        int currentSum = 0, minLen = n;

        for (int i = 0; i < n; ++i)
        {
            currentSum = (currentSum + nums[i]) % p;

            int needed = (currentSum - target + p) % p;

            if (modMap.find(needed) != modMap.end())
                minLen = min(minLen, i - modMap[needed]);

            modMap[currentSum] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};
// @lc code=end

// Note: hash table + prefix sum

// Official Solution