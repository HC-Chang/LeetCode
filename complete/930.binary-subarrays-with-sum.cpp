/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> hash;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (sum == goal)
                cnt++;
            if ((sum - goal >= 0) && hash[(sum - goal)])
                cnt += hash[(sum - goal)];

            hash[sum]++;
        }

        return cnt;
    }
};
// @lc code=end

// Note: hash table / sliding window