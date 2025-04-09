/*
 * @lc app=leetcode id=3375 lang=cpp
 *
 * [3375] Minimum Operations to Make Array Values Equal to K
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        unordered_set<int> s;
        int min_val = INT_MAX;
        for (auto x : nums)
        {
            if (x < k)
            {
                return -1;
            }
            min_val = min(min_val, x);
            s.insert(x);
        }
        return s.size() - (min_val == k);
    }
};
// @lc code=end
