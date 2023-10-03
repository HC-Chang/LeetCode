/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int cnt = 0;
        vector<int> hash(101);
        for (int i = 0; i < nums.size(); ++i)
            cnt += hash[nums[i]]++;
        return cnt;
    }
};
// @lc code=end

// Note: hash