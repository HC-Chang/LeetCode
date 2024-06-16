/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */

// @lc code=start
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long long miss = 1;
        int cnt = 0;
        size_t i = 0;

        while (miss <= n)
        {
            if (i < nums.size() && nums[i] <= miss)
                miss += nums[i++];
            else
            {
                miss += miss;
                cnt++;
            }
        }

        return cnt;
    }
};
// @lc code=end
